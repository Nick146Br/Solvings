#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
using namespace std;
typedef long long ll;
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// erase(s.upper_bound(val))
// memset(dp, -1, sizeof dp);

ll mod = 1e9 + 7;
vector<vector<ll>> adj;
vector<ll> team;
vector<bool> vis;

void bfs(int pos){
    queue<ll> q;
    q.push(pos);
    team[pos] = 0;
    vis[pos] = true;
    while(!q.empty()){
        ll a = q.front(); q.pop();
        for(auto x: adj[a]){
            if(vis[x])continue;
            vis[x] = true;
            team[x] = !team[a];
            q.push(x);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, a, b;
    cin >> n >> m;
    adj = vector<vector<ll>> (n+1);
    vector<pair<ll,ll>> gd;
    while(m--){
        cin >> a >> b;
        gd.push_back({a, b});
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    team = vector<ll> (n+1);
    vis = vector<bool> (n+1);
    for(int i = 1; i <= n; i++){
        if(!vis[i])bfs(i);
    }
    for(auto [r,s]: gd){
        if(team[r] == team[s]){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    for(int i = 1; i<= n; i++){
        cout << team[i] + 1 << " "; 
    }
    cout << "\n";
}
   
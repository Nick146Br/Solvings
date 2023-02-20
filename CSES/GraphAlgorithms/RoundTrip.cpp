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
vector<ll> dist;
vector<bool> vis;
vector<ll> pai;
int fim = -1;

void dfs(int pos){
    
    for(auto x: adj[pos]){
        if(fim != -1)return;
        if(vis[x]){
            if(dist[pos] + 1 - dist[x] > 2){
                fim = x;
                pai[x] = pos; 
                return;
            }
            continue;
        }
        vis[x] = true;
        dist[x] = dist[pos] + 1;
        pai[x] = pos;
        dfs(x);
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
    dist = vector<ll> (n+1);
    vis = vector<bool> (n+1);
    pai = vector<ll> (n+1, -1);
    for(int i = 1; i <= n; i++){
        if(!vis[i] && fim == -1)dfs(i);
    }

    if(fim == -1) cout << "IMPOSSIBLE\n";
    else{
        ll x = pai[fim];
        vector<ll> r;
        r.push_back(fim);
        while(x != fim){
            r.push_back(x);
            x = pai[x];
        }
        r.push_back(x);
        reverse(r.begin(), r.end());
        cout << r.size() << "\n";
        for(int i = 0; i < r.size(); i++){
            cout << r[i] << " ";
        }
    }
}
   
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, a, b;
    cin >> n >> m;
    vector<vector<ll>> adj(n+1);
    while(m--){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<ll> dist(n+1, 1e17);
    vector<bool> vis(n+1, 0);
    vector<ll> pai (n+1, -1);

    dist[1] = 0;
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        tie(a, b) = pq.top();pq.pop();
        if(vis[b])continue;
        vis[b] = true;
        for(auto to: adj[b]){
            if(dist[to] > dist[b] + 1){
                dist[to] = dist[b] + 1;
                pai[to] = b;
                pq.push({-dist[to], to});
            }
        }
    }
    if(dist[n] >= 1e17){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    int x = pai[n];
    vector<ll> res;
    res.push_back(n);
    while(x != -1){
        res.push_back(x);
        x = pai[x];
    }
    reverse(res.begin(), res.end());
    cout << res.size() << "\n";
    for(auto u: res)cout << u << " ";
    cout << "\n";
}
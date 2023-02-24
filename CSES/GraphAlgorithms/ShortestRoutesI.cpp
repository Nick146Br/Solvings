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
    ll n, m, a, b, c; cin >> n >> m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    priority_queue<pair<ll,ll>> pq;
    vector<ll> vis(n+1);
    vector<ll> dist(n+1, 1e17);

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        // adj[b].push_back({a, c});
    }
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()){
        tie(c, a) = pq.top();pq.pop();
        if(vis[a])continue;
        vis[a] = true;
        c = -c;
        for(auto [u, w]: adj[a]){
            if(dist[a] + w < dist[u]){
                dist[u] = dist[a] + w;
                pq.push({-dist[u], u});
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
    cout << "\n";
}
   
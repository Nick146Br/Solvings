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


void dfs(int pos, vector<bool> &vis, vector<vector<ll>> &adj){
    if(vis[pos])return;
    vis[pos] = true;

    for(auto x: adj[pos]){
        dfs(x, vis, adj);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, a, b, c; cin >> n >> m;

    vector<ll> dist (n+1, -1e17);
    
    vector<tuple<ll,ll,ll>> v;
    
    vector<vector<ll>> adj(n+1);
    vector<vector<ll>> adjrev(n+1);

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adjrev[b].push_back(a);
        v.push_back({a, b, c});
    }   


    dist[1] = 0;
    for(int i = 1; i <= n-1; i++){
        for(auto [at, to, d]: v){
            dist[to] = max(dist[to], dist[at] + d);
        }
    }

    vector<bool> vis(n+1), vis2(n+1);
    
    dfs(1, vis, adj);
    dfs(n, vis2, adjrev);

    for(auto [at, to, d]: v){
        ll ant = dist[to];
        dist[to] = max(dist[to], dist[at] + d);
        if(ant != dist[to]){
            if(vis[to] && vis2[to]){
                cout << "-1\n";
                return 0;
            }
        }
    }
    cout << dist[n] << "\n";
}
   
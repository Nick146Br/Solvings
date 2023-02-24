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
    ll n, m, a, b, c, q; cin >> n >> m >> q;
   
    vector<vector<ll>> dist (n+1, vector<ll> (n+1, 1e17));

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = dist[a][b];
    }

    for(int i = 1; i <= n; i++){
        dist[i][i] = 0;
    }
    
    for(int centro = 1; centro <= n; centro++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] =  min(dist[i][j], dist[i][centro] + dist[centro][j]);
            }
        }
    }
    while(q--){
        cin >> a >> b;
        if(dist[a][b] >= 1e17)cout << "-1\n";
        else cout << dist[a][b] << "\n";
    }
}
   
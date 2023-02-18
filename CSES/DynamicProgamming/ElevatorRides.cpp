#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
using namespace std;
typedef long long ll;
template<class T> using ordered_set =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// erase(s.upper_bound(val))
 
ll mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m; cin >> n >> m;
    vector<ll> v(n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    ll tot = (1LL << n);
    vector<pair<ll, ll>> dp (tot+1, {n+1, 0});
    dp[0] = {0, 0};
    for(int j = 0; j <= tot; j++){
        for(int i = 1; i <= n; i++){
            ll peso, rides;
            if((1LL << (i-1)) & j){
                tie(rides, peso) = dp[j^(1LL<<(i-1))];
                if(peso + v[i] <= m) peso += v[i];
                else{
                    peso = v[i];
                    rides++;
                }
                dp[j] = min(dp[j], {rides, peso});
            }
        }
    }
    cout << dp[tot-1].first + 1 << "\n";
    
}
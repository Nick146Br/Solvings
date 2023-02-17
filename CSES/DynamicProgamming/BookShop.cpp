#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
using namespace std;
typedef long long ll;
template<class T> using ordered_set =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// erase(s.upper_bound(val))
 
#define mod 1000000007


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, x;
    cin >> n >> x;
    
    vector<ll> dp (x+1, 0);
    vector<ll> pag (n+1),val (n+1);

    for(int i = 1; i <= n; i++) cin >> val[i];
    for(int i = 1; i <= n; i++) cin >> pag[i];


    for(int j = 1; j <= n; j++){
        for(int i = x; i >= val[j]; i--){
            dp[i] = max(dp[i-val[j]] + pag[j], dp[i]);
        }
    }
    ll ma = 0;
    for(int i = 1; i <= x; i++){
        ma = max(ma, dp[i]);
    }
    cout << ma << "\n";
    
}

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
using namespace std;
typedef long long ll;
template<class T> using ordered_set =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// erase(s.upper_bound(val))
 
ll mod = 1e9 + 7;

ll pot(ll a, ll b){
    ll ans = 1LL;
    while(b){
        if(b & 1)ans = (ans*a) % mod;
        a = (a*a) % mod;
        b >>= 1;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    ll soma = (n*(n+1))/2;
    if(soma & 1){cout << "0\n"; return 0;}
    soma >>= 1;
    vector<vector<ll>> dp (soma+1, vector<ll>(n+1));
    for(int i = 0; i <= n; i++){
        dp[0][i] = 1;
    }
    for(int i = 1; i <= soma; i++){
        for(int j = 1; j <= n; j++){
            if(i >= j) dp[i][j] = dp[i-j][j-1];
            dp[i][j] += dp[i][j-1];
            if(dp[i][j] > mod) dp[i][j] %= mod;
        }
    }
    cout <<( dp[soma][n]*pot(2, mod-2) ) % mod << "\n";
}
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
using namespace std;
typedef long long ll;
template<class T> using ordered_set =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// erase(s.upper_bound(val))
 
ll mod = 1e9 + 7;
 
ll dp[1000001][2] = {0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, n;
    cin >> t;
    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i = 2; i <= 1000000; i++){
        dp[i][0] = (4*dp[i-1][0] + dp[i-1][1]) % mod;
        dp[i][1] = (dp[i-1][0] + 2*dp[i-1][1]) % mod;
    }
    while(t--){
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % mod << "\n";
    }
}
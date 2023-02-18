#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
using namespace std;
typedef long long ll;
template<class T> using ordered_set =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// erase(s.upper_bound(val))
 
#define mod 1000000007

int dp[100001][103] = {0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for(int i = 1; i <= n; i++){
        if(v[i]){
            if(i>1)dp[i][v[i]] = ((dp[i-1][v[i]-1] + dp[i-1][v[i]+1])% mod  + dp[i-1][v[i]]) % mod;
            else dp[i][v[i]] = 1;
            continue;
        }
        for(int j = 1; j <= m; j++){
            if(i>1) dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % mod + dp[i-1][j];
            else dp[i][j] = 1;
            if(dp[i][j] > mod) dp[i][j] %= mod;
        }
    }
    ll soma = 0;
    for(int i = 1; i <= m; i++){
        soma += dp[n][i];
        if(soma > mod)soma %= mod;
    }
    cout << soma << "\n";
    
    
}

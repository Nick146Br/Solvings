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
    
    ll n;
    cin >> n;
    vector<vector<ll>> dp;
    vector<vector<char>> G;
    dp = vector<vector<ll>> (n+1, vector<ll> (n+1, 0));
    G = vector<vector<char>> (n+1, vector<char> (n+1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> G[i][j];
        }
    }
    if(G[1][1] != '*')dp[1][1] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if((i == 1 && j == 1) || G[i][j] == '*')continue;
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            if(dp[i][j] > mod)dp[i][j] %= mod;
        }
    }
    cout << dp[n][n] << "\n";
}

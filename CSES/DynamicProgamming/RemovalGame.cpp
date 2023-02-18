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
    ll n; cin >> n;
    vector<vector<ll>> dp;
    vector<ll> v(n+2);
    n++;
    for(int i = 2; i <= n; i++){
        cin >> v[i];
    }
    // sort(v.begin()+1, v.end());
    dp = vector<vector<ll>> (n+5, vector<ll> (n+5, 0));
    for(int i = 2; i <= n; i++){
        dp[i][i] = v[i];
    }
    for(int i = n; i >= 2; i--){
        for(int j = i+1; j <= n; j++){
            dp[i][j] = max(min(dp[i+2][j], dp[i+1][j-1]) + v[i], min(dp[i+1][j-1], dp[i][j-2]) + v[j]);
        }
    }
    cout << dp[2][n] << "\n";
}
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
    ll a, b; cin >> a >> b;
    vector<vector<ll>> dp (a + 1, vector<ll> (b + 1, 1e17));
    
    ll mi = min(a, b);
    for(int i = 0; i <= mi; i++){
        dp[i][i] = 0;
    }
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            for(int k = 1; k <= max(i, j); k++){
                ll res = 1e17;
                if(k < i) res = min(res, dp[i-k][j] + dp[k][j] + 1);
                if(k < j) res = min(res, dp[i][j-k] + dp[i][k] + 1);
                dp[i][j] = min(dp[i][j], res);
            }
        }
    }
    
    cout << dp[a][b] << "\n";
}
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
    string a, b; cin >> a >> b;
    vector<vector<ll>> dp (a.size() + 1, vector<ll> (b.size() + 1));
    ll n, m;
    n = a.size();
    m = b.size();
    a = '+' + a;
    b = '+' + b;
    for(int i = 1; i <= n; i++){
        dp[i][0] = i;
    }
    for(int i = 1; i <= m; i++){
        dp[0][i] = i;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1];
            }
            else dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
        }   
    }
    cout << dp[n][m] << "\n";
}
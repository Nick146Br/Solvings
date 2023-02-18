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
    vector<vector<bool>> dp;
    ll soma = 0;
    vector<ll> v(n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        soma += v[i];
    }
    sort(v.begin()+1, v.end());
    dp = vector<vector<bool>> (soma+1, vector<bool> (n+1, false));
    for(int i = 0; i <= n; i++){
        dp[0][i] = true;
    }
    vector<ll> res;
    for(int i = 1; i <= soma; i++){
        bool flag = false;
        for(int j = 1; j <= n; j++){
            bool ans = false;
            if(v[j] <= i)ans = dp[i-v[j]][j-1];
            ans = ans || dp[i][j-1];
            dp[i][j] = ans;


            if(dp[i][j] && !flag){
                res.push_back(i);
                flag = true;
            }
        }
    }
    cout << res.size() << "\n";
    for(auto x: res) cout << x << " ";
    cout << "\n";
}
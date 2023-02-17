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
    
    
    ll n, m;
    cin >> n >> m;
    vector<ll> sum(m+1, 1e17);
    vector<ll> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    sum[0] = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < n && coins[j] <= i; j++){
            sum[i] = min(sum[i], sum[i - coins[j]] + 1);
            // if(sum[i] > mod)sum[i] %= mod;
        }
    }
    if(sum[m] >= 1e17)cout << "-1\n";
    else cout << sum[m] << "\n";
}

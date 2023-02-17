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
    
    
    ll n, m;
    cin >> n >> m;
    vector<ll> sum(m+1);
    vector<ll> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
 
    sum[0] = 1;
    for(int j = 0; j < n; j++){
        for(int i = coins[j]; i <= m; i++){
            sum[i] += sum[i - coins[j]];
            if(sum[i] > mod)sum[i] %= mod;
        }
    }
    cout << sum[m] << "\n";
}

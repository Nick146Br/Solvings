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
    
    
    ll n;
    cin >> n;
    vector<ll> sum(n+1);
    sum[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6 && j <= i; j++){
            sum[i] += sum[i - j];
            if(sum[i] > mod)sum[i] %= mod;
        }
    }
    cout << sum[n] << "\n";
}

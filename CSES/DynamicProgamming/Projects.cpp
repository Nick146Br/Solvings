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
    vector<tuple<ll,ll,ll>> v(n);
    vector<ll> dp (n+2, 0);
    ll a, b, c;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        v[i] = {a, b, c};
    }
    sort(v.begin(), v.end());
    for(int i = n; i >= 1; i--){
        tie(a, b, c) = v[i-1];
        tuple<ll,ll,ll> t = {b, 1e17, 1e17};
        int ind = upper_bound(v.begin(), v.end(), t) - v.begin();
        ll ans = 0;
        if(ind != v.size())ans = dp[ind+1];
        dp[i] = max(ans + c, dp[i+1]);
    }
    cout << dp[1] << "\n";
}
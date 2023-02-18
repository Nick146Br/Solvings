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
    vector<ll> v;
    for(int i = 1; i <= n; i++){
        ll x; cin >> x;
        auto it = lower_bound(v.begin(), v.end(), x);
        if(it == v.end()) v.push_back(x);
        else *it = x;
    }

    cout << v.size() << "\n";
}
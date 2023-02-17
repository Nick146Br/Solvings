#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
using namespace std;
typedef long long ll;
template<class T> using ordered_set =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// erase(s.upper_bound(val))


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n+1);
    vector<ll> prefix(n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        prefix[i] = prefix[i-1] + v[i];
    }
    multiset<ll> s;
    ll ma = -1e17;
    for(int i = a; i <= b; i++){
        s.insert(prefix[i]);
    }
    for(int i = 1; i <= n-a+1; i++){
        auto it = s.end();
        it--;
        ma = max(ma, *it - prefix[i-1]);

        s.erase(s.lower_bound(prefix[i+a-1]));
        
        if(i + b <= n)s.insert(prefix[i+b]);
        
        
    }
    cout << ma << "\n";
}

// Solution 2 --------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
using namespace std;
typedef long long ll;
template<class T> using ordered_set =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// erase(s.upper_bound(val))


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n+1);
    vector<ll> prefix(n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        prefix[i] = prefix[i-1] + v[i];
    }
    multiset<ll> s;
    ll ma = -1e17;
    s.insert(prefix[0]);
    for(int i = a; i <= n; i++){    
        
        
        auto it = s.begin();
        ma = max(ma, prefix[i] - *it);

        s.insert(prefix[i-a+1]);
        if(i>=b)s.erase(s.lower_bound(prefix[i-b]));
        
        
           
    }
    cout << ma << "\n";
}

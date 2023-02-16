#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
using namespace std;
typedef long long ll;
template<class T> using ordered_set =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    ll ini = 0, fim = k-1;
    ordered_set <ll> s;
    // multiset<ll> m; 
    for(int i = ini; i < fim; i++){
        s.insert(v[i]);
        // m.insert(v[i]);:
    }
    while(fim < n){
        // m.insert(v[fim]);
        s.insert(v[fim]);
        ll meio = k/2;
        auto it = s.find_by_order(meio);
        if(k % 2 == 0)it--;
        cout << *it << " ";
        
     
        // m.erase(m.lower_bound(v[ini]));
        s.erase(s.upper_bound(v[ini]));
        fim++;
        ini++;
    }
    cout << "\n";

 
}
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long ll;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k; cin >> n >> k;

    ordered_set<int>v;
    for(int i = 1; i <= n; i++){
        v.insert(i);
    }
    ll i = 0;
    while(v.size()){
        i = (i+k)%v.size();
        auto it = v.find_by_order(i);
        cout << *it << " ";
        v.erase(it);
    }
    cout << "\n";
 
 
}
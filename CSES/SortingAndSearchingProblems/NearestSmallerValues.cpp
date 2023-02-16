#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long ll;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].second = -i;
    }
    sort(v.begin(), v.end());

    set<ll> aux; 
    vector<ll> res(n);
    for(int i = 0; i < n; i++){
        ll a = -v[i].second;
        if(!aux.size()){
            res[a] = -1;
            aux.insert(a);
            continue;
        }
        auto it = aux.lower_bound(a);
        if(it != aux.begin())it--;
        if(*it >= a)res[a] = -1;
        else res[a] = *it;
        
        aux.insert(a);
    }
    for(auto x: res)cout << x + 1 << " ";
    cout << "\n";
}
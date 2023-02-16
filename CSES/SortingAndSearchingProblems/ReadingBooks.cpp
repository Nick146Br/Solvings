#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long ll;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

bool comp(pair<ll,ll> a, pair<ll,ll> b){
    if(a.first == b.first){
        return a.second > b.second;
    }

    return a.first < b.first;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll soma = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        soma += v[i];
    }
    sort(v.begin(), v.end());
    ll fim = v.size()-1;
    
    if(2*v[fim] >= soma){
        cout << 2*v[fim] << "\n";
    }
    else cout << soma << "\n";
    
}
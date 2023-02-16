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
    ll n, soma;
    cin >> n >> soma;
    
    vector<ll> v(n+1);
    vector<ll> prefix(n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        prefix[i] = v[i] + prefix[i-1];
    }
    ll cont = 0;
    map<ll, ll> mp;
    mp[0] = 1;
    for(int i = 1; i <= n; i++){
        cont += mp[prefix[i] - soma];
        mp[prefix[i]]++;
    }

    cout << cont << "\n";


}
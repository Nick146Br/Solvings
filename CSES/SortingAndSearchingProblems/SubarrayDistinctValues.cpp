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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    ll ini = 0, fim = 0, qnt = 0;
    map<ll,ll>elem;
    ll ans = 0;
    while(ini < n){
        while(fim < n && qnt + (elem[v[fim]] == 0) <= k){
            if(!elem[v[fim]])qnt++;
            elem[v[fim]]++;
            fim++;
        }
        ans += fim - ini;
        elem[v[ini]]--;
        if(elem[v[ini]] == 0)qnt--;
        ini++;
    }
    cout << ans  << "\n";
 
}
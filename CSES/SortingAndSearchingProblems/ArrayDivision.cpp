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
    ll soma = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        soma += v[i];
    }
    ll ini = 0, fim = soma+1;
    ll save = -1;
    while(ini <= fim){
        ll meio = (fim+ini)/2;
        soma = 0;
        ll cont = 0, ma = 0;
        for(int i = 0; i < n; i++){
            ma = max(ma, v[i]);
            if(soma + v[i] >= meio){
                if(soma + v[i] == meio) soma = 0;
                else soma = v[i];
                cont++;
            }
            else soma += v[i];
        }
        if(soma)cont++;

        if(ma <= meio && cont <= k){
            save = meio;
            fim = meio-1;
        }
        else {
            ini = meio+1;
        }
 
    }
    cout << save << "\n";

 
}
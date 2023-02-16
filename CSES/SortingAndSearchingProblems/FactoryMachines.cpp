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
    ll n, t;
    cin >> n >> t;
    ll ini = 1, fim = 1e18;
    ll save = -1;
    vector<ll> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    while(ini <= fim){
        ll meio = ini + (fim - ini) / 2;
        ll prd = 0;
        for(int i = 0; i < n; i++){
            prd += meio/v[i];
            if(prd > t)break;
        }
        if(prd >= t){
            fim = meio-1;
            save = meio;
        }
        else{
            ini = meio+1;
        }
    }
    cout << save << "\n";

}
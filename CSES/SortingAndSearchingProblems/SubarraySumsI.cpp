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
    
    vector<ll> v(n);
    
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    ll val = 0;
    ll ini = 0, cont = 0;
    
    for(int i = 0; i < n; i++){
        if(val > soma){
            val -= v[ini++];
            i--;
        }else{
            if(val==soma)cont++;
            val += v[i];
        }
    }

    while(ini < n){
        val -= v[ini++];
        if(val == soma)cont++;
    }
    cout << cont << "\n";


}
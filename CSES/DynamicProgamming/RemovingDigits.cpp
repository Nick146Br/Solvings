#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
using namespace std;
typedef long long ll;
template<class T> using ordered_set =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// erase(s.upper_bound(val))
 
#define mod 1000000007
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, cont = 0;
    cin >> n;
    while(n){
        ll aux = n;
        ll ma = 0;
        while(aux){
            ma = max(ma, aux%10);
            aux /= 10;
        }
        n -= ma;
        cont++;
    }
    cout << cont << "\n";
}

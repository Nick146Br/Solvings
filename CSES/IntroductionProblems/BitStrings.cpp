#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
ll mod = 1e9 + 7;

ll pot(ll a, ll b){
    ll ans = 1LL;
    while(b){
        if(b&1){
            ans *= a;
            if(ans>=mod) ans%=mod;
        }
        a *= a;
        if(a>=mod) a%=mod;
        b >>= 1;
    }
    return ans;
    
}
int main(){
    ll n; cin >> n;
    ll res = pot(2LL, n);
    cout << res << "\n";
} 
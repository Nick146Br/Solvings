#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pot(ll a, ll b){
    ll ans = 1LL;
    while(b){
        if(b&1)ans *= a;
        a = a*a;
        b >>= 1;
    }
    return ans;
}
int main(){
    ll t; cin >> t;
    while(t--){    
        ll n, m;
        cin >> n >> m;
        if(n%2 == 0 || m%2 == 0){
            cout << "2\n";
        }
        else{
            cout << "12\n";
        }
        // cout << __gcd(pot(5, n) + pot(7, n), (pot(5, m) + pot(7, m))) << "\n";
    }
}
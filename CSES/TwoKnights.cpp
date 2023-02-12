#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main(){
    ll n; cin >> n;
    for(ll i = 1; i <= n; i++){
        ll comb = ((i*i)*(i*i-1))/2;
        ll res = comb - max(0LL, (i-1)*(i-2)*4LL);
        cout << res << "\n";
    }
} 
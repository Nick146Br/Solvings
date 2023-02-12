#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
ll mod = 1e9 + 7;
 
int main(){
    ll n; cin >> n;
    ll r = 5;
    ll res = 0;
    while(r <= n){
        res += (n/r);
        r*=5;
    }
    cout << res << "\n";
} 
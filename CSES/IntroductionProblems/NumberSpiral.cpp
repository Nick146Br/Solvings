#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll x, y;
        cin >> x >> y;
        ll ma = max(x, y);
        ll val = 2*(ma-1);
        ll soma = ((2 + val)*(ma-1))/2;
        if(ma == y){
            if(ma & 1) cout << soma + 1 + (y-x) << "\n";
            else cout << soma + 1 - (y-x) << "\n";
        }
        else{
            if(ma & 1) cout << soma + 1 - (x-y) << "\n";
            else cout << soma + 1 + (x-y) << "\n";
        }
    }
 
}
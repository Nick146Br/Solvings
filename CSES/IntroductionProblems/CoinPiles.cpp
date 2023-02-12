#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
ll mod = 1e9 + 7;

int main(){
    ll n; cin >> n;
    while(n--){
        ll a, b; cin >> a >> b;
        
        if(a > b)swap(a, b);
        
        if(a*2 < b){
            cout << "NO\n";
            continue;
        }
        a%=3; b%=3;
        if((a == 1 && b == 2) || (a == 2 && b == 1) || (a == 0 && b == 0)) cout << "YES\n";
        else cout << "NO\n";
    }
}
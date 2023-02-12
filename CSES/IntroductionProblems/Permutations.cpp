#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    if(n == 1){
        cout << "1\n";
        return 0;
    }
    vector<ll> v(n);
    int meio = n/2;
    ll val = n-3;
    v[meio] = n;
    int i = meio-1;
    while(i >= 0 && val >= 1){
        v[i] = val;
        i--;
        val-=2;
    }
    val = n-2;
    i = meio+1;
    while(i <= n-1 && val <= n){
        v[i] = val;
        i++;
        val-=2;
    }
    v[0] = n-1;
    string res = "";
    for(int i = 0; i < n; i++){
        if(i != 0){
            if(abs(v[i] - v[i-1]) == 1){
                cout << "NO SOLUTION\n";
                return 0;
            }
        }
        res += to_string(v[i]) + " ";
    }
    cout << res << "\n";
 
}
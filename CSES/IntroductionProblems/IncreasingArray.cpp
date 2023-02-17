#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<ll> v(n);
    ll cont = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(i != 0){
            if(v[i] < v[i-1]){
                cont += v[i-1] - v[i];
                v[i] = v[i-1];
            }
        }
    }
    cout << cont << "\n";
 
}
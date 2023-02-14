#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll meio = n/2;
    ll median = (n & 1) ?  v[meio] : (v[meio] + v[meio-1])/2;
    ll soma = 0;
    for(int i = 0; i < n; i++){
        soma += abs(v[i] - median);
    }
    cout << soma << "\n";
}

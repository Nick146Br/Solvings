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
    ll sum = 0, ma = -1e17;
    for(int i = 0; i < n; i++){
        sum = max(v[i],sum + v[i] );
        ma = max(ma, sum);
    }
    cout << ma << "\n";
}

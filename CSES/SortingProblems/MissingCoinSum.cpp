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
    ll ans = 1;
    for(int i = 0; i < n; i++){
        if(v[i] > ans){
            cout << ans << "\n";
            return 0;
        }
        ans += v[i];
    }
    cout << ans << "\n";
}

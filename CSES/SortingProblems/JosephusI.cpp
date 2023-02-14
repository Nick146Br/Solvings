#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x; cin >> n;
    set<ll> s;
    vector<ll> prx(n+1);
    vector<ll> ant(n+1);
    for(int i = 1; i <= n; i++){
        ant[i] = i == 1 ? n : i-1;
        prx[i] = i == n ? 1 : i+1;
    }
    ll pos = 1;
    pos = prx[pos];
    for(int i = 0; i < n; i++){
        prx[ant[pos]] = prx[pos];
        ant[prx[pos]] = ant[pos];
        cout << pos << " ";
        pos = prx[prx[pos]];
    }
    cout << "\n";
}

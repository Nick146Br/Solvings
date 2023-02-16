#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x; cin >> n;
    vector<bool> qnt(n+1);
    map<ll,ll> mp;
    ll cont = 0;
    ll ma = 0, pos;
    pos = 0;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(mp.count(x)){
            pos = max(pos, mp[x]+1);
        }
        mp[x] = i;
        ma = max(ma, i - pos + 1);
        // qnt[v[i]] = {0, i};
    }
    cout << ma << "\n";
}

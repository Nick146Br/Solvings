#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        ll cont = 0, x;
        map<ll,ll> mp1;
        for(int i = 0; i < n; i++){
            vector<ll> v;
            for(int j = 0; j < m; j++){
                cin >> x;
                v.push_back(x);
                if(i!=0){
                    if(mp1[x]){
                        cont++;
                        mp1[x]--;
                    }
                }
            }
            mp1.clear();
            for(int j = 0; j < m; j++){
                mp1[v[j]]++;
            }
        }
        cout << cont << "\n";
    }
}
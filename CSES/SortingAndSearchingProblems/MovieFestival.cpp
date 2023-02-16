#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, a, b; cin >> n;
    vector<pair<ll,ll>> v;
    for(int i= 0; i < n; i++){
        cin >> a >> b;
        v.push_back({b, a});
    }
    sort(v.begin(), v.end());
    ll cont = 0;
    ll fim = 0;
    for(int i = 0; i < n; i++){
        if(v[i].second >= fim){
            fim = v[i].first;
            cont++;
        }
    }
    cout << cont << "\n";
}

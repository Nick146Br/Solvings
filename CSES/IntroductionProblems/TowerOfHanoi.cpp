#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
ll mod = 1e9 + 7;

vector<pair<ll,ll>> res;

void gerar(ll ini, ll meio, ll fim, ll n){
    if(n == 1){
        res.push_back({ini, fim});
        return;
    }

    gerar(ini, fim, meio, n-1);
    res.push_back({ini, fim});
    gerar(meio, ini, fim, n-1);

}

int main(){
    ll n; cin >> n;
    gerar(1, 2, 3, n);
    cout << res.size() << "\n";
    for(auto x: res){
        cout << x.first << " " << x.second << "\n";
    }
}
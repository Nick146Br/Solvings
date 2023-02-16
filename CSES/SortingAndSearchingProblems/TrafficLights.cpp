#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x, a, ma; cin >> x >> n;
    multiset<ll> s;
    vector<ll> v;
    for(int i = 0; i < n; i++){
        cin >> a;
        v.push_back(a);
        s.insert(a);
    }
    ma = 0;
    s.insert(0); s.insert(x);
    vector<ll> res;
    reverse(v.begin(), v.end());
    ll at = 0;
    for(auto u: s){
        ma = max(u - at , ma);
        at = u;
    }
    res.push_back(ma);
    for(int i = 0; i < n; i++){
        auto ind = s.lower_bound(v[i]);
        auto prox = ind, ant = ind;
        prox++;
        if(ind != s.begin())ant--;
        ll soma = 0;
        if(prox != s.end()){
            soma = *prox - *ind;
        }
        soma += *ind - *ant;
        ma = max(ma, soma);
        res.push_back(ma);
        s.erase(ind);
    }
    for(int i = res.size() - 2; i >= 0; i--){
        cout << res[i] << " ";
    }
    cout << "\n";
}

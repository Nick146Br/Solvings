#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m; cin >> n >> m;
    vector<ll> v(n);
    vector<pair<ll,ll>> qnt(n+2);

    for(int i = 0; i < n; i++){
        cin >> v[i];
        qnt[v[i]] = {0, i};
    }
    for(int i = 0; i < n; i++){
        if(qnt[v[i]-1].first != 0){
            qnt[v[i]].first = qnt[v[i]-1].first + 1;
            qnt[v[i]-1].first = 0;
        }
        else qnt[v[i]].first = 1;
    }
    ll cont = 0;
    for(int i = 0; i < n; i++){
        if(qnt[v[i]].first)cont++;
    }
    while(m--){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        if(a > b)swap(a, b);
        ll dif = abs(v[a] - v[b]);
        if(dif == 1){
            if(v[a] > v[b])cont--;
            else cont++;
        }
        
        if(qnt[v[b] + 1].second < b && qnt[v[b] + 1].second > a){
            cont--;
        }
        if(qnt[v[a] - 1].second > a && qnt[v[a] - 1].second < b){
            cont--;
        }
        if(qnt[v[b] - 1].second > a && qnt[v[b] - 1].second < b){
            cont++;
        }
        if(qnt[v[a] + 1].second < b && qnt[v[a] + 1].second > a){
            cont++;
        }
        
        qnt[v[b]].second = a;
        qnt[v[a]].second = b;
        swap(v[a], v[b]);
        cout << cont << "\n";
    }
}

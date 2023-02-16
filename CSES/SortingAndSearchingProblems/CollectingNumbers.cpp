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
    vector<ll> qnt(n+1, 0);
    for(int i = 0; i < n; i++){
        if(qnt[v[i]-1] != 0){
            qnt[v[i]] = qnt[v[i]-1] + 1;
            qnt[v[i]-1] = 0;
        }
        else qnt[v[i]] = 1;
    }
    ll cont = 0;
    for(int i = 0; i < n; i++){
        if(qnt[v[i]])cont++;
    }
    cout << cont << "\n";
}

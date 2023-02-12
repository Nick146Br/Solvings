#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
ll mod = 1e9 + 7;
ll mi = 1e17;

vector<ll> v;

void gerar(ll soma, ll total, ll pos){
    if(pos == v.size())return;
    mi = min(mi, abs(total-2*soma));
    gerar(soma+v[pos], total, pos+1);
    gerar(soma, total, pos+1);

}

int main(){
    ll n; cin >> n;
    v = vector<ll> (n+1);
    ll total=0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        total += v[i];
    }
    gerar(0, total, 0);
    cout << mi << "\n";
}
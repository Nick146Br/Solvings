#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pot(ll a, ll b){
    ll ans = 1LL;
    while(b){
        if(b&1)ans *= a;
        a = a*a;
        b >>= 1;
    }
    return ans;
}
int main(){
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll k = 0, i = 0, ant = 0;
        while(k < n){
            ant = k;
            k += 9*pot(10,i)*(i+1);
            i++;
        }
        ll res = n-ant;
        ll qnt = res/i;
        ll resto = res%i;
        qnt = qnt + pot(10, (i-1)) - 1;
        string s;
        if(resto == 0){
            s = to_string(qnt);
            cout << s[s.size()-1] << "\n";
        }
        else{
            qnt++;
            s = to_string(qnt);
            cout << s[resto-1] << "\n";
        }
    }
}
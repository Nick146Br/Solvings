#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main(){
    ll n; cin >> n;
    ll soma = (n*(n+1))/2;
    if(soma & 1)cout << "NO\n";
    else{
        soma = soma/2;
        cout << "YES\n";
        ll meio = 0;
        set<ll> s;
        for(int i = n; i >= 1; i--){
            if(meio + i > soma) break;
            meio += i;
            s.insert(i);
        }
        if(soma - meio != 0) s.insert(soma - meio);
        cout << s.size() << "\n";
        for(auto x: s) cout << x << " ";
        cout << "\n";
        cout << n-s.size() << "\n";
        for(int i = 1; i <= n; i ++){
            if(s.count(i))continue;
            cout << i << " ";
        }
        cout << "\n";
 
    }
} 
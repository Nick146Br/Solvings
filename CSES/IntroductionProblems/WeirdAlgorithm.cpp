#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
ll cont = 0;
string res;
string aux;
vector<string> rs;
 
void bt(int pos, int w1, int w2, int w3, int n){
    if(w1 > 1 || w2 > 1 || w3 > 1)return;
    if(pos == n){
        cont++;
        if(cont > 1){
            cout << "Ambiguous\n";
            exit(0);
        }
        for(int i = 0; i < n; i++){
            res[i] = aux[i];
        }
        return;
    }
    char l1, l2, l3;
 
    l1 = rs[0][pos];
    l2 = rs[1][pos];
    l3 = rs[2][pos];
 
    if(l1 == l2 && l1 == l3){
        aux[pos] = l1;
        bt(pos+1, w1, w2, w3, n);
        return;
    }
 
    set<char> conj;
    conj.insert(l1); 
    conj.insert(l2); 
    conj.insert(l3);
    conj.insert('z' + 4);
 
    for(auto letra: conj){
        aux[pos] = letra;
        bt(pos+1, w1 + !(l1 == letra), w2 + !(l2 == letra), w3 + !(l3 == letra), n);
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    while(n != 1){
        cout << n << " ";
        if(n&1)n = 3*n+1;
        else n = n/2;
    }
    cout << "1\n";
}
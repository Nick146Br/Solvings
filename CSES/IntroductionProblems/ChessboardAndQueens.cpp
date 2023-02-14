#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
ll mod = 1e9 + 7;
 
vector<ll> v;
vector<bool> colunas (9);
vector<bool> diagp(20);
vector<bool> diags(9);
vector<vector<char>> M;
ll cont = 0;
 
void gerar(ll i){
    if(i == 8){
        cont++;
        return;
    }
    for(int j = 0; j < 8; j++){
        if(colunas[j] || diagp[8+(i-j)] || diags[i+j] || M[i][j] == '*')continue;
        colunas[j] = true; diagp[8+(i-j)] = true; diags[i+j] = true;
        gerar(i+1);
        colunas[j] = false; diagp[8+(i-j)] = false; diags[i+j] = false;
    }
    
}
 
int main(){
    M = vector<vector<char>> (9, vector<char> (9));
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> M[i][j];
        }
    }
    gerar(0);
    cout << cont << "\n";
}
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
ll mod = 1e9 + 7;
 
vector<bool> vis;
string res;
 
bool gerar(ll k){
    
    if(vis[k])return false;
    vis[k] = true;
    cout << res << "\n";
    for(int i = 0; i < res.size(); i++){
        res[i] = (res[i] == '0') ? '1' : '0';
        bool flag = gerar(k ^ (1LL << i));
        if(flag)break;
        res[i] = (res[i] == '0') ? '1' : '0';
    }
    return true;
 
}
 
int main(){
    ll n; cin >> n;
    vis = vector<bool> ((1LL << n) + 1LL, false);
 
    for(int i = 0; i < n; i++){
        res += '0';
    }
    gerar(0);
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1, s2, s3;
 
vector<bool> vis;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, h, w;
    cin >> n >> m >> h >> w;
    vector<vector<ll>> prefix (n+1, vector<ll> (m+1));
    vector<vector<ll>> M(n+1, vector<ll> (m+1));
    vector<vector<ll>> aux(n+1, vector<ll> (m+1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> M[i][j];
        }
    }
    ll ini = 1, fim = n*m;
    ll save = 0;
    while(ini <= fim){
        ll meio = (ini+fim)/2;
        bool flag = false;
        ll cont = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(M[i][j] > meio) aux[i][j] = 1;
                else aux[i][j] = -1;
                // else aux[i][j] = 0;
            }
        }
        if((h*w) % 2 == 0)cont-=2;
        else cont--;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + aux[i][j];
            }
        }
        for(int i = h; i <= n; i++){
            for(int j = w; j <= m; j++){
                ll res = prefix[i][j] - prefix[i-h][j] - prefix[i][j-w] + prefix[i-h][j-w];
                if(res <= 0){
                    flag = true;
                    i = n+1;
                    break;
                }
            }
        }
        if(flag){
            save = meio;
            fim = meio-1;
        }
        else{
            ini = meio+1;
        }
    }
    cout << save << "\n";
}
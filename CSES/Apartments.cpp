#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, x; cin >> n >> m >> x;
    ll cont = 0;
    vector<ll> mo(n), c(m); 
    for(int i = 0; i < n; i++){
        cin >> mo[i];
    }
    for(int i = 0; i < m; i++){
        cin >> c[i];
    }
    sort(mo.begin(), mo.end());
    sort(c.begin(), c.end());
    int j = 0;
    for(int i = 0; i < n; i++){
        if(mo[i] + x >= c[j] && mo[i] - x <= c[j]){
            cont++;
            j++;
            if(j >= m)break;
        }
        else if(mo[i] - x > c[j]){
            j++;
            if(j >= m)break;
            i--;
        }
    }

    cout << cont << "\n";

}

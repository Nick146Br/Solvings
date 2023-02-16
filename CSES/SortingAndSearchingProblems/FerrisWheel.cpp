#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, w;
    cin >> n >> w;
    vector<ll> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll cont = 0;
    ll p = w;
    int j = n-1, i = 0;
    while(i <= j){
        if(v[j] <= p){
            p -= v[j];
            j--;
        }
        if(v[i] <= p){
            p -= v[i];
            i++;
        }
        p = w;
        cont++;

    }
    cout << cont << "\n";

}

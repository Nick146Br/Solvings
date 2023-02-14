#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, a, b; cin >> n;
    vector<pair<ll,ll>> v;
    for(int i= 0; i < n; i++){
        cin >> a >> b;
        v.push_back({a, 0});
        v.push_back({b, 1});
    }
    sort(v.begin(), v.end());
    ll cont = 0;
    ll ma = 0;
    for(int i = 0; i < 2*n; i++){
        if(v[i].second == 1){
            cont--;
            cont = max(0LL, cont);
        }
        else{
            cont++;
            ma = max(ma, cont);
        }
    }

    cout << ma << "\n";
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, a, x; cin >> n >> x;
    vector<pair<ll, ll>> v;
    for(int i= 0; i < n; i++){
        cin >> a;
        v.push_back({a, i+1});
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        pair<ll,ll> p = {x-v[i].first, -1};
        int ind = lower_bound(v.begin(), v.end(), p) - v.begin();
        if(ind != v.size() && ind != i){
            if(v[i].first + v[ind].first == x){
                cout << v[i].second << " " << v[ind].second << "\n";
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << "\n";
}

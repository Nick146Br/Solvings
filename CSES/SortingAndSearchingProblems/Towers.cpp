#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x; cin >> n;
    vector<pair<ll,ll>> v;
    multiset<ll> s;
    for(int i = 0; i < n; i++){
        cin >> x;
        auto ind = s.upper_bound(x);
        if(ind != s.end()){
            s.erase(ind);
        }
        s.insert(x);
        v.push_back({x, i});
    }

    cout << s.size() << "\n";
}

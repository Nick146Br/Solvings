#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long ll;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

bool comp(pair<ll,ll> a, pair<ll,ll> b){
    if(a.first == b.first){
        return a.second > b.second;
    }

    return a.first < b.first;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<pair<ll,ll>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            pair<ll,ll> p = {m-v[i].first-v[j].first, -1};
            int ind = lower_bound(v.begin() + j + 1, v.end(), p) - v.begin();
            if(ind == v.size())continue;
            if(v[ind].first + v[i].first + v[j].first == m){
                cout << v[i].second + 1 << " " << v[j].second + 1 << " " << v[ind].second + 1 << "\n";
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}
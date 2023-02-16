#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long ll;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<tuple<ll,ll,ll>> sm;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            sm.push_back({v[i] + v[j], i, j});
        }
    }
    sort(sm.begin(), sm.end());

    for(int i = 0; i < sm.size(); i++){
        tuple <ll,ll,ll> t = {m- get<0>(sm[i]), -1, -1};
        int ind = lower_bound(sm.begin() + i + 1, sm.end(), t) - sm.begin();
        if(ind == sm.size())continue;
        if(get<0>(sm[i]) + get<0>(sm[ind]) == m){
            unordered_set<ll> s;
            s.insert(get<1>(sm[i]));
            s.insert(get<2>(sm[i]));
            s.insert(get<1>(sm[ind]));
            s.insert(get<2>(sm[ind]));
            if(s.size() == 4){
                cout << get<1>(sm[i]) + 1 << " " << get<2>(sm[i]) + 1 << " " << get<1>(sm[ind]) + 1 << " " << get<2>(sm[ind]) + 1 << "\n";
                return 0;
            }
        }

    }
    cout << "IMPOSSIBLE\n";
}
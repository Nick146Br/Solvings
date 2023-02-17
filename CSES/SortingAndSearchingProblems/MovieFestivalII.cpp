#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
using namespace std;
typedef long long ll;
template<class T> using ordered_set =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// erase(s.upper_bound(val))

vector<ll> bit1, bit2;

#define SM false
#define CNT true

void update(bool c, int idx, int val, ll n){
    if(c){
        while (idx <= n) {
            bit1[idx]+=val;
            idx += idx & (-idx);
        }
    }
    else{
        while (idx <= n) {
            bit2[idx]+=val;
            idx += idx & (-idx);
        }
    }
}

ll query(bool c, int idx){
    ll ans = 0;
    if(c){
        while (idx) {
            ans += bit1[idx];
            idx -= idx & (-idx);
        }
    }
    else{
        while (idx) {
            ans += bit2[idx];
            idx -= idx & (-idx);
        }
    }
    return ans;
}

bool comp (pair<ll,ll> a, pair<ll,ll> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, a, b, k;
    cin >> n >> k;
    vector<pair<ll,ll>> v;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), comp);

    multiset<ll> s;
    for(int i = 0; i < k; i++){
        s.insert(0);
    }
    ll cont = 0;
    for(int i = 0; i < n; i++){
        tie(a, b) = v[i];
        auto it = s.lower_bound(a);
        if(it != s.begin())it--;
        if(*it > a)continue;
        cont++;
        s.erase(it);
        s.insert(b);
    }
    cout << cont << "\n";
 
}
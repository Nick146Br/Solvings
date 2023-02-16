#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long ll;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

vector<ll> bit;

ll tamanho;

void update(int idx, int val){
    while (idx <= tamanho) {
        bit[idx]+=val;
        idx += idx & (-idx);
    }
}

int query(int idx){
    int ans = 0;
    while (idx) {
        ans += bit[idx];
        idx -= idx & (-idx);
    }
    return ans;
}

bool comp(tuple<ll,ll,ll> a, tuple<ll,ll,ll> b){
    ll x, y, z; tie(x,y,z) = a;
    ll r, s, t; tie(r,s,t) = b;
    if(x == r) return y < s;
    return x > r;
}
bool comp1(tuple<ll,ll,ll> a, tuple<ll,ll,ll> b){
    ll x, y, z; tie(x,y,z) = a;
    ll r, s, t; tie(r,s,t) = b;
    if(y == s) return x < r;
    return y > s;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<ll, ll> mp;
    
    ll a, b, n; cin >> n;
    vector<tuple<ll,ll,ll>> v;
    vector<pair<ll,ll>> g;
    vector<ll> aux;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        aux.push_back(a);
        aux.push_back(b);
        g.push_back({a, b});
    }
    sort(aux.begin(), aux.end());
    ll cont = 1;
    for(int i = 0; i < aux.size(); i++){
        mp[aux[i]] = cont++;
    }
    tamanho = cont;
    bit = vector<ll> (tamanho+1);
    for(int i = 0; i < n; i++){
        a = mp[g[i].first];
        b = mp[g[i].second];
        v.push_back({mp[g[i].first], mp[g[i].second], i});
    }
    sort(v.begin(), v.end(), comp);
    vector<ll> res(n);

    ll ini, end, idx;
    for(int i = 0; i < v.size(); i++){
        tie(ini, end, idx) = v[i];
        res[idx] = query(end);
        update(end, 1);
    }
    for(auto x: res)cout << x << " ";
    cout << "\n";
    
    sort(v.begin(), v.end(), comp1);
    bit = vector<ll> (tamanho+1);

    for(int i = 0; i< v.size(); i++){
        tie(ini, end, idx) = v[i];
        res[idx] = query(ini);
        update(ini, 1);
    }

    for(auto x: res)cout << x << " ";
    cout << "\n";
}
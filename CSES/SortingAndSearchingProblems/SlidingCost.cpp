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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    vector<ll> aux;
    map<ll,ll> mp;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        aux.push_back(v[i]);
    }
    sort(aux.begin(), aux.end());
    for(int i = 0; i < n; i++){
        mp[aux[i]] = i+1;
    }
    ll ini = 0, fim = k-1;
    ordered_set <ll> s; 
    
    ll meio = k/2;
    bit1 = bit2 = vector<ll> (n+2);


    for(int i = ini; i < fim; i++){
        update(CNT, mp[v[i]], 1, n+1);
        update(SM, mp[v[i]], v[i], n+1);
        s.insert(v[i]);
    }

    while(fim < n){
        update(CNT, mp[v[fim]], 1, n+1);
        update(SM, mp[v[fim]], v[fim], n+1);
        s.insert(v[fim]);
    
        auto it = s.find_by_order(meio);
        
        if(k % 2 == 0) it--;

        ll val = *it;
        ll sd, se, qd, qe;
        se = query(SM, mp[val]-1);
        qe = query(CNT, mp[val]-1);
        sd = query(SM, n+1) - query(SM, mp[val]);
        qd = query(CNT, n+1) - query(CNT, mp[val]);
        
        cout << sd - qd*val - se + qe*val  << " ";

        s.erase(s.upper_bound(v[ini]));
        update(CNT, mp[v[ini]], -1, n+1);
        update(SM, mp[v[ini]], -v[ini], n+1);
        fim++;
        ini++;
    }
    cout << "\n";

 
}
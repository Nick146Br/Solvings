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
    ll n, a, b;
    cin >> n;
    vector<pair<ll, ll>> v;
    for(int i = 1; i <= n; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), comp);
    ll time = 0;
    ll soma = 0;
    for(int i = 0; i < n; i++){
        time += v[i].first;
        soma += v[i].second - time; 
    }
    cout << soma << "\n";
}
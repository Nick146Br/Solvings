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
    ll n, a, b; cin >> n;
    vector<tuple<ll, ll,ll>> v;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back({a, 0, i});
        v.push_back({b, 1, i});
    }
    vector<ll> room(n+1);
    ll ind = 1;
    stack<ll> p;
    sort(v.begin(), v.end());
    ll c;
    for(int i = 0; i < 2*n; i++){
        tie(a, b, c) = v[i];
        if(b == 0){
            if(p.empty())
                room[c] = ind++;
            else{
                room[c] = p.top();p.pop();
            }
        }
        else{
            p.push(room[c]);
        }
    }
    cout << ind-1 << "\n";
    for(int i = 0; i < n;i++){
        cout << room[i] << " ";
    }
    cout << "\n";
}
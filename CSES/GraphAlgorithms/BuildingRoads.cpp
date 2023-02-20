#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
using namespace std;
typedef long long ll;
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// erase(s.upper_bound(val))
// memset(dp, -1, sizeof dp);

ll mod = 1e9 + 7;

vector<ll> pai;
vector<ll> tam;


ll find(ll x){
    if(pai[x] == x)return x;
    return pai[x] = find(pai[x]);
}

void unite(ll a, ll b){
    ll x = find(a);
    ll y = find(b);
    if(x == y)return;
    if(tam[y] > tam[x])swap(x, y);
    pai[y] = x;
    tam[x] += tam[y];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, a, b;
    cin >> n >> m;
    tam = vector<ll> (n+1);
    pai = vector<ll> (n+1);
    for(int i = 1; i <= n; i++){
        pai[i] = i;
        tam[i] = 1;
    }
    while(m--){
        cin >> a >> b;
        unite(a, b);
    }
    set<ll> s;
    vector<ll> res;
    for(int i = 1; i <= n; i++){
        s.insert(find(i));
    }
    for(auto x: s){
        res.push_back(x);
    }
    cout << res.size() - 1 << "\n";
    for(int i = 1; i < res.size(); i++){
        cout << res[i] << " " << res[i-1] << "\n";
    }

}
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
using namespace std;
typedef long long ll;
template<class T> using ordered_set =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// erase(s.upper_bound(val))


vector<ll> v;

struct node{
    ll soma;
    ll prefix;
    ll sufix;
    ll meio;
};

vector<node> st;

struct node f(struct node e, struct node d){
    struct node k;
    k.prefix = max(e.prefix, e.soma + d.prefix);
    k.sufix = max(d.sufix, e.sufix + d.soma);
    k.meio = max({e.meio, d.meio, d.prefix + e.sufix});
    k.soma = e.soma + d.soma;
    return k;
}

void build(int pos, int ini, int fim){
    if(ini == fim){
        struct node k;
        k.soma = v[ini];
        k.prefix = v[ini];
        k.sufix = v[ini];
        k.meio = v[ini];
        st[pos] = k;
        return;
    }

    int mid = (ini+fim)/2;
    int e = 2*pos;
    int d = 2*pos + 1;

    build(e, ini, mid);
    build(d, mid+1, fim);
 
    st[pos] = f(st[e],st[d]);

}

void update(int pos, int ini, int fim, int id, int val){
    if(id < ini || id > fim)return;

    if(ini == fim){
        struct node k;
        k.soma = val;
        k.prefix = val;
        k.sufix = val;
        k.meio = val;
        st[pos] = k;
        return;
    }

    int mid = (ini+fim)/2;
    int e = 2*pos;
    int d = 2*pos + 1;

    update(e, ini, mid, id, val);
    update(d, mid+1, fim, id, val);
 
    st[pos] = f(st[e],st[d]);

}
struct node query(int pos, int ini, int fim, int l, int r){
    if(r < ini || l > fim){
        struct node k;
        k.soma = 0;
        k.prefix = 0;
        k.sufix = 0;
        k.meio = 0;
        return k;
    }
     if(l <= ini && fim <= r)return st[pos];

    int mid = (ini+fim)/2;
    int e = 2*pos;
    int d = 2*pos + 1;

    struct node q1 = query(e, ini, mid, l, r);
    struct node q2 = query(d, mid+1, fim, l, r);
 
    return f(q1, q2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m;
    cin >> n >> m;
    v = vector<ll> (n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    st = vector<node> (4*n + 1);
    build(1, 1, n);
    while(m--){
        ll a, b; cin >> a >> b;
        update(1,1,n,a, b);
        cout << max(0LL, query(1, 1, n, 1, n).meio) << "\n"; 

    }
 
}

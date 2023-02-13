#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAX 1e17
struct node{
    ll size;
    node(){
        size = 0;
    }
};

vector<ll> v;
vector<node> st;

node f(node e, node d){
    node k;
    k.size = max(e.size, d.size);
    return k;
}
void build(int pos, int ini, int fim){
    if(ini == fim){
        node k;
        k.size = v[ini];
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


node query(int pos, int ini, int fim, int l, int r){


    if(r < ini || l > fim){
        node k;
        return k;
    }
     if(l <= ini && fim <= r)return st[pos];

    int mid = (ini+fim)/2;
    int e = 2*pos;
    int d = 2*pos + 1;

    node q1 = query(e, ini, mid, l, r);
    node q2 = query(d, mid+1, fim, l, r);
 
    return f(q1, q2);
}

ll bb(ll pos, ll ini, ll fim, ll k){
    if(k > st[pos].size)return MAX;
    if(ini == fim){
        return ini;
    }
    ll mid = (ini + fim) >> 1;
    ll e = 2*pos;
    ll d = 2*pos + 1;
    if(k <= st[d].size){
        return bb(d, mid+1, fim, k);
    }
    else{
        return bb(e, ini, mid, k);
    }
}

#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

int main(){
    fast_io
    ll t; cin >> t;
    while(t--){
        ll n, m, q; cin >> n >> m >> q;
        st = vector<node>(4*m);
        v = vector<ll> (m+1);

        for(int i = 1; i <= n; i++){
            ll l, r;
            cin >> l >> r;
            for(int j = l; j <= r; j++){
                v[j] = -1;
            }
        }
        for(int i = 1; i <= m; i++){
            ll cont = 0;
            // int ini = i;
            bool flag = false;
            while(i <= m && v[i] == 0){
                cont++;
                i++;
                flag = true;
            }
            if(flag)i--;
            v[i] = cont;
        }
        build(1, 1, m);

        while(q--){
            ll tam; cin >> tam;
            ll res = bb(1, 1, m, tam);
            if(res >= MAX)cout << "-1 -1\n";
            else cout << res - tam + 1 << " " << res << "\n";
        }
    }
}
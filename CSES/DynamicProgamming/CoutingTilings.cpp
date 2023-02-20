#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
using namespace std;
typedef long long ll;
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// erase(s.upper_bound(val))
 
ll mod = 1e9 + 7;

ll dp[1002][1025];

vector<ll> arr;
ll n, m;

void gerar_mask(ll ant, ll prox, int posn, vector<ll> &gd){
    if(posn == n){
        gd.push_back(prox);
        return;
    }
    if(!(ant & (1LL << posn))){
        if(posn != n-1){
            if(!(ant & (1LL << (posn+1)))){
                gerar_mask(ant, prox, posn+2, gd);
            }
        }
        gerar_mask(ant, prox | (1LL << posn), posn+1, gd);
    }
    else{
        gerar_mask(ant, prox, posn+1, gd);
    }
}
ll rec(int posm, ll ant){

    if(dp[posm][ant] != -1)return dp[posm][ant];
    
    if(posm == m){
        if(ant == 0) return 1;
        return 0;
    }

    ll res = 0;
    vector<ll> gd;
    gerar_mask(ant, 0, 0, gd);
    for(auto mask: gd){
        res += rec(posm+1, mask);
        if(res > mod) res %= mod;
    }
    return dp[posm][ant] = res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    ll ans = rec(0, 0);
    cout << ans << "\n";
}
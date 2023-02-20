#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
using namespace std;
typedef long long ll;
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// erase(s.upper_bound(val))
 
ll mod = 1e9 + 7;

ll dp[20][20][2][2];

vector<ll> arr;

ll getSum(int pos, int ant, bool flag, bool flag2, ll n){
    if(pos > n)return 1;
    if(dp[pos][ant][flag][flag2] != -1)return dp[pos][ant][flag][flag2];
    ll limit = 9;
    ll res = 0;
    if(flag)limit = arr[pos];
    for(int i = 0; i <= limit; i++){
        if(flag2 && ant == i)continue;
        if(flag && i == limit){
            if(i == 0) res += getSum(pos+1, i, true, flag2, n);
            else res += getSum(pos+1, i, true, true, n);
        }
        else{
            if(i == 0) res += getSum(pos+1, i, false, flag2, n);
            else res += getSum(pos+1, i, false, true, n);
        }
    }
    return dp[pos][ant][flag][flag2] = res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof dp);
    ll res = 0;
    if(a)a--;
    else res++;
    while(a>0){
        arr.push_back(a%10);
        a/=10;
    }
    
    reverse(arr.begin(), arr.end());
    ll tam = arr.size();
    ll res1 = getSum(0, 11, true, false, tam-1);

    arr.clear();
    memset(dp, -1, sizeof dp);
    while(b>0){
        arr.push_back(b%10);
        b/=10;
    }
    reverse(arr.begin(), arr.end());
    tam = arr.size();
    ll res2 = getSum(0, 11, true, false, tam-1);

    res += res2 - res1;
    cout << res << "\n";
}
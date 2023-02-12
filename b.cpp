#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pot(ll a, ll b){
    ll ans = 1LL;
    while(b){
        if(b&1)ans *= a;
        a = a*a;
        b >>= 1;
    }
    return ans;
}
int main(){
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        string s;
        int i = 1;
        for(; i <= 1000000; i++){
            s = to_string(i);
            if(n >= s.size()){
                n -= s.size();
                if(n==0)break;
            }
            else break;
        }
        if(n == 0){
            cout << s << "\n";
            cout << s[s.size()-1] << "\n";
        }
        else{
            cout << s << "\n";
            cout << s[n-1] << "\n";
        }
    }
}
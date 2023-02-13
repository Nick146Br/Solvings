#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t; cin >> t;
    while(t--){
        string s;
        ll n, m; cin >> n >> m;
        cin >> s;
        map<char, ll> mp;
        string num;
        cin >> num;
        for(int i = 0; i < num.size(); i++){
            ll x = num[i] - '0';
            if(!mp.count(s[i]))mp[s[i]] = x;
            else mp[s[i]] = min(mp[s[i]], x);
        }
        bool flag = true;
        ll custo = 0;
        string r; cin >> r;
        for(int i = 0; i < r.size(); i++){
            if(!mp.count(r[i])){
                flag = false;
                break;
            }
            custo += mp[r[i]];
        }
        if(flag){
            cout << custo << "\n";
        }
        else cout << "-1\n";
    }
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t; cin >> t;
    while(t--){
        string s;
        cin >> s;
        // bool flag = false;
        ll cont = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z')cont++;
        }
        if(cont <= 7){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
}
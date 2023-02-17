#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    ll cont = 1, ma = 1;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i-1]){
            cont++;
            ma = max(cont, ma);
        }
        else cont = 1;
    }
    cout << ma << "\n";
}
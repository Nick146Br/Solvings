#include <bits/stdc++.h>
using namespace std;

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
int main()
{
    fast_io     
    ll x;
    cin >> x;
    for(int i=0;i<x;i++){
        string s;
        cin >> s;
        ll ver = s[0]-'a';
        bool f = 1;
        for(int i=1;i<s.size();i++){
            ver++;
            if(ver>'z'-'a'){
                ver = 0;
            }
            if(s[i]-'a' != ver){
                f = 0;
                break;
            }
        }
        if(f)cout << "YES\n";
        else cout << "NO\n";
    }

}
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
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        ll ans = abs(a-c) + abs(b-d);
        cout << ans << "\n";
    }


}
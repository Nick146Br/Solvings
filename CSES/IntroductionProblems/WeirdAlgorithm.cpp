#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    while(n != 1){
        cout << n << " ";
        if(n&1)n = 3*n+1;
        else n = n/2;
    }
    cout << "1\n";
}
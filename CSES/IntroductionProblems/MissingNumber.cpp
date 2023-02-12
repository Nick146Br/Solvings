#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> v(n-1);
    ll mex = 1;
    for(int i = 0; i < n-1; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n-1; i++){
        if(v[i] == mex)mex++;
        else{
            cout << mex << "\n";
            return 0;
        }
    }
    cout << mex << "\n";
}
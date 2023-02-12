#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, x; cin >> n;
        set<ll> s;
        for(int i = 0; i < n; i++){
            cin >> x;
            if(s.count(x))s.insert(x+1);
            else s.insert(x);
        }
        cout << s.size() << "\n";
    }
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, x;
    cin >> n >> m;
    multiset<ll> s;
    
    for(int i = 0; i < n; i++){
        cin >> x;
        s.insert(x);
    }

    for(int i = 0; i < m; i++){
        cin >> x;
        auto it = s.lower_bound(x);
        if(s.size() == 0 || (it == s.begin() && *it > x)){
            cout << "-1\n";
            continue;
        }
        if(it == s.end() || *it > x)it--;
        cout << *it << "\n";
        s.erase(it);
    }

}

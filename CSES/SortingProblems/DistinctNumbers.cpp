#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x; cin >> n;
    set <ll> s;
    for(int i =0; i <n; i++){
        cin >> x;
        s.insert(x);
    }
    cout <<s.size() << "\n";

}

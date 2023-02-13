#include <bits/stdc++.h>

#define MAX
#define MOD

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        set <ll> res;
        set <ll> ant;

        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            set<ll> aux;
            for(auto k: ant){
                aux.insert(x | k);
            }
            aux.insert(x);
            
            for(auto k : aux)res.insert(k);

            ant = aux;
        }
        cout << res.size() << "\n";
        
    }

    return 0;
}
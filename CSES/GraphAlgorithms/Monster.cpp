#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
using namespace std;
typedef long long ll;
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// erase(s.upper_bound(val))
// memset(dp, -1, sizeof dp);

ll mod = 1e9 + 7;

vector<vector<ll>> adj;

vector<vector<ll>> tempo;

vector<pair<ll,ll>> mov = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

map<ll,char> mp;

vector<vector<tuple<ll,ll, char>>> pai;

vector<vector<char>> M;

int fimx = -1, fimy = -1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    mp[0] = 'D';
    mp[1] = 'U';
    mp[2] = 'R';
    mp[3] = 'L';

    ll n, m;
    cin >> n >> m;
    
    adj = vector<vector<ll>> (n+1);
    
    M = vector<vector<char>> (n+1, vector<char> (m+1));
    vector<pair<ll,ll>> mon;
    tempo = vector<vector<ll>> (n+1, vector<ll> (m+1, 1e17));

    ll inix, iniy;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> M[i][j];
            if(M[i][j] == 'A'){
                if(i == 0 || i == n-1 || j == m-1 || j == 0){
                    cout << "YES\n";
                    cout << "0\n";
                    return 0;
                }
                inix = i;
                iniy = j;
                tempo[i][j] = 0;
            }
            if(M[i][j] == 'M'){
                tempo[i][j] = 0;
                mon.push_back({i, j});
            }
            if(M[i][j] == '#')tempo[i][j] = 0;
        }
    }
    
    pai = vector<vector<tuple<ll,ll, char>>> (n+1, vector<tuple<ll,ll,char>>(m+1, {-1,-1, '*'}));

    queue<tuple<ll,ll,ll>> q;

    for(int i = 0; i < mon.size(); i++){
        q.push({mon[i].first, mon[i].second, 0});
    }

    
    int a, b, tmp;

    while(!q.empty()){
        tie(a, b, tmp) = q.front(); q.pop();
        int a1 = a, b1 = b;
        for(int i = 0; i < mov.size(); i++){
            a = a1 + mov[i].first;
            b = b1 + mov[i].second;

            if(a < 0 || b < 0 || a == n || b == m || M[a][b] == '#' || M[a][b] == 'M')continue;
            if(tempo[a][b] <= tmp + 1)continue;
            
            
            tempo[a][b] = tmp+1;
            q.push({a, b, tmp + 1});       
        }
    }
    bool flag = false;

    q.push({inix, iniy, 0});
    while(!q.empty()){
        
        tie(a, b, tmp) = q.front(); q.pop();
        int a1 = a, b1 = b;
        for(int i = 0; i < mov.size(); i++){
            a = a1 + mov[i].first;
            b = b1 + mov[i].second;

            if(a < 0 || b < 0 || a == n || b == m || M[a][b] == '#' || M[a][b] == 'M')continue;
            if(tempo[a][b] <= tmp + 1)continue;
            
            pai[a][b] = {a1, b1, mp[i]};
            
            if(a == 0 || b == 0 || a == n-1 || b == m-1){
                fimx = a; fimy = b;
                flag = true;
                break;
            }
            
            tempo[a][b] = tmp+1;
            q.push({a, b, tmp + 1});       
        }
        if(flag)break;
    }
    if(fimx == -1) cout << "NO\n";
    else{
        cout << "YES\n";
        ll x, y;
        char c;
        tie(x, y, c) = pai[fimx][fimy];
        vector<char> r;
        while(c != '*'){
            r.push_back(c);
            tie(x, y, c) = pai[x][y];
        }
        reverse(r.begin(), r.end());
        cout << r.size() << "\n";
        for(int i = 0; i < r.size(); i++){
            cout << r[i];
        }
        cout << "\n";
    }
}
   
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
using namespace std;
typedef long long ll;
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// erase(s.upper_bound(val))
 
ll mod = 1e9 + 7;
 
vector<vector<char>> M;
vector<vector<bool>> vis;
 
 
vector<pair<ll,ll>> mov = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
 
ll n, m;
 
void bfs(ll posx, ll posy){
    if(vis[posx][posy])return;
    vis[posx][posy] = true;
    queue<pair<ll,ll>> q;
    q.push({posx, posy});
    while(!q.empty()){
        ll x, y;
        tie(x, y) = q.front(); q.pop();
        for(int i = 0; i < mov.size(); i++){
            ll ax = x + mov[i].first;
            ll ay = y + mov[i].second;
            if(ax == -1 || ay == -1 || ax == n || ay == m || M[ax][ay] == '#')continue;
            if(!vis[ax][ay]){
                vis[ax][ay] = true;
                q.push({ax, ay});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vis = vector<vector<bool>> (n+1, vector<bool> (m+1));
    M = vector<vector<char>> (n+1, vector<char> (m+1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> M[i][j];
        }
    }
    ll cont = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(M[i][j] == '.' && !vis[i][j]){
                bfs(i, j);
                cont++;
            }
        }
    }
    cout << cont << "\n";
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
// vector<vector<bool>> vis;
string s;

#define MAX 7

vector<int> p1 = {-1, 0, 1, 0};
vector<int> p2 = {0, 1, 0, -1};
// vector<pair<int,int>> p = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<int> v;
bool vis[MAX+2][MAX+2];

ll CHAMA = 0;
int recurs(int pos, int x, int y){
    CHAMA++;
    if((vis[x][y-1] && vis[x][y+1]) && (!vis[x-1][y] && !vis[x+1][y])){
        return 0;
    }
    if((vis[x-1][y] && vis[x+1][y]) && (!vis[x][y+1] && !vis[x][y-1])){
        return 0;
    }
    
    if(x == MAX && y == 1){
        if(pos == 48)return 1;
        return 0;
    }
    if(pos == 48)return 0;
    
    vis[x][y] = true;

    int res = 0;
    if(v[pos] < 4){
        int posx, posy;
        int ind = v[pos];    
        posx = x+p1[ind];
        posy = y+p2[ind];
        if(!vis[posx][posy])
        res = recurs(pos+1, posx, posy);
    }
    else{
        for(int i = 0; i < 4; i++){
            int posx, posy;
            
            posx = x+p1[i];
            posy = y+p2[i];
            if(vis[posx][posy])continue;
            res += recurs(pos+1, posx, posy);
        }
    }
    vis[x][y] = false;
    return res;
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    getline(cin, s);
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'R')v.push_back(1);
        else if(s[i] == 'L')v.push_back(3);
        else if(s[i] == 'U')v.push_back(0);
        else if(s[i] == 'D')v.push_back(2);
        else v.push_back(4);
    }
    for(int i = 0; i <= MAX+1; i++){
        vis[i][0] = true;
        vis[i][MAX+1] = true;
        vis[MAX+1][i] = true;
        vis[0][i] = true;
    }
    for(int i = 1; i <= 7; i++){
        for(int j = 1; j <= 7; j++){
            vis[i][j] = false;
        }
    }
    // vis[1][1] = true;
    int ans = recurs(0, 1, 1);
    cout << ans << "\n";
    // cout << CHAMA << "\n";
}

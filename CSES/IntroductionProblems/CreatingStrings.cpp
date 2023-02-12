#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
ll mod = 1e9 + 7;

string s;
vector<bool> vis;
set<string> ans;
void gerar(string res){
    if(res.size() == s.size()){
        ans.insert(res);
        return;
    }
    for(int i = 0; i < s.size(); i++){
        if(vis[i])continue;
        vis[i] = true;
        gerar(res + s[i]);
        vis[i] = false;
    }

}

int main(){
    cin >> s;
    vis = vector<bool> (s.size() + 1, false);
    gerar("");
    cout << ans.size() << "\n";
    for(auto x: ans){
        cout << x << "\n";
    }
}
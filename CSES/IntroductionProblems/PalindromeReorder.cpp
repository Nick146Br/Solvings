#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
ll mod = 1e9 + 7;

int main(){
    string s; cin >> s;
    map<char, ll> mp;
    bool flag = true;
    string res;
    if(s.size() & 1){
        bool first = false;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }
        for(auto x: mp){
            if(x.second & 1){
                if(first){
                    flag = false;
                    break;
                }
                first = true;
            }
        }
        if(!flag)cout << "NO SOLUTION\n";
        else{
            char c;
            for(auto x: mp){
                if(x.second & 1){
                    c = x.first;
                    mp[c]--;
                }
                
                for(int i =0; i < x.second/2; i++)
                    res += x.first;
            } 
            string aux = res;
            reverse(aux.begin(), aux.end());
            cout << res + c + aux << "\n";
        }
    }
    else{
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }
        for(auto x: mp){
            if(x.second & 1){
                flag = false;
                break;
            }
            else{
                for(int i =0; i < x.second/2; i++)
                    res += x.first;
            }
        }
        if(!flag){
            cout << "NO SOLUTION\n";
        }
        else{
            string aux = res;
            reverse(aux.begin(), aux.end());
            cout << res + aux << "\n";
        }
    }
}
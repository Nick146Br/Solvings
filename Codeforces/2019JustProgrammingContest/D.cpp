#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1, s2, s3;
 
vector<bool> vis;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t--){
        string ans;
        ll a0, b0, c0, a1, b1, c1;
        a0 = 0; b0 = 0; c0 = 0; b1 = 0; c1 = 0; a1 = 0;
        cin >> s1 >> s2 >> s3;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] == '0')a0++;
            else a1++;
            if(s2[i] == '0')b0++;
            else b1++;
            if(s3[i] == '0')c0++;
            else c1++;
        }
        for(int i = 0; i < s1.size(); i++){
            if(a1 < b1){ // a1 o cara que tem mais uns;
                swap(a1, b1);
                swap(a0, b0);
            }
            if(b1 < c1){
                swap(b1, c1);
                swap(b0, c0);
            }
            if(a1 < b1){
                swap(a1, b1);
                swap(a0, b0);
            }
            if(a1 && b0 && c0){
                ans += '1';a1--;b0--;c0--;
            }
            else if(a1 && b1 && c1){
                ans += '1';a1--;b1--;c1--;
            }
            else ans += '0';
        }
        cout << ans << "\n";
    }
}
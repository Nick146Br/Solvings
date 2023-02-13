#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int mi = 119;
        ll sum = 0;
        priority_queue<int> pq;
        
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            mi = min(mi, abs(x));
            
            if(x > 0)
                sum += x;
            else
                pq.push(-x);
        }
        
        while(!pq.empty() && k){
            sum += pq.top();
            pq.pop();
            k--;
        }
        
        while(!pq.empty()){
            sum += -pq.top();
            pq.pop();
        }
        
        if(k % 2)
            sum -= 2 * mi;
        
        cout << sum << "\n";
    }

    return 0;
}
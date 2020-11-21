#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, x;
    cin >> x >> n;
    vector<int>coins(x);
    for(int i = 0; i < x; i ++){
        cin >> coins[i];
    }
    vector<int>dp(n + 1, -1);
    dp[0] = 0;
    for(int i = 1; i <= n; i ++){
        int curr = INT_MAX;
        for(auto x: coins){
            if(i-x >= 0 && dp[i - x] != -1){
                curr = min(curr, dp[i - x] + 1);
            }
        }
        if(curr != INT_MAX){
            dp[i] = curr;
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
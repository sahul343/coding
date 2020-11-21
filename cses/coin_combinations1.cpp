#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, x, mod = 1e9 + 7;
    cin >> x >> n;
    vector<int>coins(x);
    for(int i = 0; i < x; i ++){
        cin >> coins[i];
    }
    vector<int>dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i ++){
        for(auto x: coins){
            if(i - x >= 0){
                dp[i] += dp[i - x];
                dp[i] = (dp[i]) % mod;
            }
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
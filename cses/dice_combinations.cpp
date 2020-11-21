#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, mod = 1e9 + 7;
    cin >> n;
    vector<int>dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= 6 && (i-j) >= 0; j++){
            dp[i] += dp[i - j];
            dp[i] = dp[i] % mod;
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
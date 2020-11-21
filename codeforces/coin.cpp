#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "Please Enter the Amount\n";
    cin >> n;
    vector<int>dp(n + 1, -1);
    dp[0] = 0;
    for(int i = 1; i <= n; i ++){
        int curr = dp[i - 1] + 1;
        if(i >= 2 && dp[i - 2] != -1) curr = min(curr, dp[i - 2] + 1);
        if(i >= 5 && dp[i - 5] != -1) curr = min(curr, dp[i - 5] + 1);
        dp[i] = curr;
    }
    cout << "The minimum number of coins required for " << n << " is " << dp[n] << "\n";
    return 0;
}
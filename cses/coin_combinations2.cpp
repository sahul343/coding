#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, x, mod = 1e9 + 7;
    cin >> n >> x;
    vector<int>coins(n);
    for(int i = 0; i < n; i ++){
        cin >> coins[i];
    }
    vector<vector<int> >dp(n + 1, vector<int>(x+1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j <= x; j ++){
            dp[i][j] = dp[i - 1][j];
            int left = j - coins[i - 1];
            if(left >= 0){
                (dp[i][j] += dp[i][left]) %= mod;
            }
        }
    }
    cout << dp[n][x] << "\n";
    return 0;
}
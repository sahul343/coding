#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, mod = 1e9 + 7;
    cin >> n;
    vector<string>grid(n);
    for(string &x: grid) cin >> x;
    vector<vector<int> >dp(n, vector<int>(n+1, 0));
    
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            if(grid[i][j] != '*'){
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else if(i == 0){
                    dp[i][j] = dp[i][j - 1];
                }
                else if(j == 0){
                    dp[i][j] = dp[i - 1][j];
                }
                else{
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
                dp[i][j] %= mod;
            }
            
        }
    }
    cout << dp[n - 1][n - 1] << "\n";
    return 0;
}
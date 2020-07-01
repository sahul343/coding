#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long a[n];
    long long cum[n+1];
    memset(cum, 0,sizeof(cum));
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cum[i + 1] += cum[i] + a[i];
    }
    long long dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    for(int k = 0; k < n; k++){
        for(int i = 1; i + k <= n; i++){
            if(k == 0){
                dp[i][i] = 0;
            }
            else{
                long long ans = -1;
                //dp[i][i+k] = dp[i][j] and dp[j+1][i+k]
                for(int j = i; j < i+k; j++  ){
                    if(ans == -1){
                        ans = dp[i][j] + dp[j+1][i+k] + cum[i+k] - cum[i-1];
                    }
                    ans = min(ans, dp[i][j] + dp[j+1][i+k] + cum[i+k] - cum[i-1] );
                }
                dp[i][i+k] = ans;
            }
        }
    }
    cout << dp[1][n]  << endl;
    return 0;
}
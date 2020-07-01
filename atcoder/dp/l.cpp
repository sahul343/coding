#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    long long dp[n][n][2];
    for(int i = 0; i <n; i++){
        dp[i][i][0] = a[i];
        dp[i][i][1] = 0;
    }
    for(int k = 1; k < n; k++){
        for(int i = 0; i + k < n; i++){
            //compute dp[i][i+k][0], dp[i][i+k][1]
            if(dp[i+1][i+k][1]+a[i] - dp[i+1][i+k][0] > dp[i][i+k-1][1]+a[i+k] - dp[i][i+k-1][0]){
                dp[i][i+k][0] = dp[i+1][i+k][1] + a[i];
                dp[i][i+k][1] = dp[i+1][i+k][0];
            }
            else{
                dp[i][i+k][0] = dp[i][i+k-1][1] + a[i+k];
                dp[i][i+k][1] = dp[i][i+k-1][0];
            }
        }
    }
    cout << dp[0][n-1][0] - dp[0][n-1][1] << "\n";
    return 0;
}
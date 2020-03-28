#include<bits/stdc++.h>
using namespace std;
int m = 1e9+7;
int main(){
    int n, k; 
    cin >> n >> k;
    int a[n];
    int f[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i == 0){
            f[i] = a[0];
        }
        else{
            f[i] = f[i - 1] + a[i];
        }
    }
    int dp[n][k+1];
    int cum[n][k+1];
    memset(dp, 0, sizeof(dp));
    memset(cum, 0, sizeof(cum));
    //cum[i][j] should give sum of all dp[i][k] where 0 <= k <= j;
    for(int i = 0; i < n; i++){
        long long sum = 0;
        for(int j = 0; j <= k; j++){
            if(j == 0){
                dp[i][j] = 1;
            }
            else if(i == 0 && j <= a[i]){
                dp[i][j] = 1;
            }
            else{
                //dp[i][j] will be dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j-a[i]];
                if(j > f[i]) {
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = cum[i-1][j];
                    if(j-a[i]-1 >= 0){
                        dp[i][j] -= cum[i-1][j-a[i]-1];
                    }
                }
            }
            dp[i][j] = (dp[i][j] + m)%m;
            sum = (sum + dp[i][j]) % m;
            cum[i][j] = sum;
        }
    }
    cout << dp[n-1][k] << endl;
    
    return 0;
}

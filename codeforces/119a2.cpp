#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, a[3];
    cin >> n >> a[0] >> a[1] >> a[2];
    vector<int>dp(n+1, -1);
    dp[0] = 0;
    for(int i = 1; i <= n ;i++){
       for(int j = 0; j < 3; j++){
            if(a[j] <= i && dp[i-a[j]] != -1){
                dp[i] = max(dp[i], 1 + dp[i-a[j]]);
               // cout << i << " "<< dp[i]  << " "<< a[j]<<" " << dp[i-a[j]] << endl;
            }
       }
    }
    cout << dp[n] << endl;
    return 0;
}
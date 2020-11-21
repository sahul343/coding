#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i ++){
            cin >> a[i];
        }
        int dp[n][2];
        if(n == 1) {
            cout << a[0] << "\n";
        }
        else{
            dp[0][0] = a[0];
            dp[0][1] = 1000000;

            dp[1][0] = a[0] + a[1];
            dp[1][1] = dp[0][0];
            for(int i = 2; i < n; i ++){
                dp[i][0] = min(dp[i - 2][1] + a[i - 1], dp[i - 1][1]) + a[i];
                dp[i][1] = min(dp[i - 1][0], dp[i - 2][0]);
            }
            cout << min(dp[n - 1][0], dp[n - 1][1]) << "\n";
        }
    }
    return 0;
}
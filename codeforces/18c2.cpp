#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        if(a[i-1] == b[i-1]){
            dp[i] = dp[i-1];
        }
        else{
            dp[i] = 1 + dp[i-1];
            if( i-2 >= 0 && a[i-2] != a[i-1] && a[i-2] != b[i-2] ){
                dp[i] = min(dp[i], 1 + dp[i-2]);
            }
        }
    }
    cout << dp[n] <<"\n";
    return 0;
}
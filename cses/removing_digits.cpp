#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>dp(n + 1, 0);
    for(int i = 1; i <= n; i ++){
        dp[i] = i;
        int num = i;
        while(num){
            if((i - (num%10)) >= 0) {
                dp[i] = min(dp[i], 1 + dp[i - (num%10)]);
            }
            num /= 10;
        }
        
    }
    cout << dp[n] << "\n";
    return 0;
}
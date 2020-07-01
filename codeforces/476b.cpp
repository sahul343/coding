#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int distance = 0, n = s1.size();
    for(int i = 0; i < n; i++ ){
        if(s1[i] == '+')  distance ++;
        else distance --;
    }
    distance += n;
    double dp[n+1][2 * n+1];
    memset(dp, 0, sizeof(dp));
    dp[0][n] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 2 * n; j++){
            int delta1 = 1, delta2 = -1;
            if(s2[i-1] == '-'){
                delta1 = -1, delta2 = -1;
            }
            else if(s2[i-1] == '+'){
                delta1 = 1, delta2 = 1;
            }
            if(j + delta1 >= 0 && j + delta1 <= 2 * n){
                dp[i][j+delta1] = dp[i-1][j]*0.5;
            }
            if(j + delta2 >= 0 && j+delta2 <= 2 * n){
                dp[i][j+delta2] += dp[i-1][j]*0.5;
            }
        }
    }
    cout << setprecision(10);
    cout << dp[n][distance] << "\n";
    return 0;
}
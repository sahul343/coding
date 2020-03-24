#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, w, v = 0;
    scanf("%d %d",&n, &w);
    int weight[n], value[n];
    for(int i = 0; i < n; i++){
        scanf("%d %d",&weight[i], &value[i]);
        v += value[i];
    }
    vector<vector<long long> >dp(n+1, vector<long long>(v+1, INT_MAX));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= v; j++){
            if(j == 0){
                dp[i][j] = 0;
                continue;
            }
            else if(value[i-1] <= j){
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-value[i - 1]] + weight[i-1]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
  // cout << "value of v = " << v << endl;
    for(int i = v; i >= 0; i--){
        if(dp[n][i] <= w) {
           // cout << dp[n][i] << endl;
            printf("%d\n",i);
            break;
        }
    }
    
    return 0;
}
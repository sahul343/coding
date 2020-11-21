#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, target;
    cin >> n >> target;
    vector<pair<int,int>>books(n);
    for(int i = 0; i < n; i++){
        cin >> books[i].first;
    }
    for(int i = 0; i < n; i++){
        cin >> books[i].second;
    }
    int dp[n + 1][target + 1];
    memset(dp, 0 , sizeof(dp));
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= target; j ++){
            dp[i][j] = dp[i - 1][j];
            if(j >= books[i - 1].first){
                dp[i][j] = max(dp[i][j], books[i - 1].second + dp[i - 1][j - books[i - 1].first]);
            }
        }
    }
    cout << dp[n][target] << "\n";
    return 0;
}
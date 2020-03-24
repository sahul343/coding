#include<bits/stdc++.h>
using namespace std;
int main(){
    int m = 1e9+7;
    int h, w;
    cin >> h >> w;
    char grid[h][w];
    vector<vector<int>>dp(h, vector<int>(w,0));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> grid[i][j];
            if(grid[i][j] == '#'){
                dp[i][j] = -1;
            }
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(dp[i][j] == -1) continue;
            else if (i == 0 && j == 0) dp[i][j] = 1;
            else {
                if( i-1 >= 0 && dp[i-1][j] != -1)
                dp[i][j] += dp[i-1][j];
                if( j-1 >= 0 && dp[i][j-1] != -1)
                dp[i][j] += dp[i][j-1];
            }
            dp[i][j] = dp[i][j]%m;
        }
    }
    cout << dp[h-1][w-1] << endl;
    return 0;
}
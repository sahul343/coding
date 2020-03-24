#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, W;
    scanf("%d %d",&N, &W);
    int w[N], v[N];
    for(int i = 0; i < N; i++){
        scanf("%d %d",&w[i], &v[i]);
    }
    vector<vector<long long> > dp(N+1, vector<long long>(W+1, -1));
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= W; j++){
            if(i == 0 || j==0) {
                dp[i][j] = 0;
                continue;
            }
            if( j >= w[i-1]){
                dp[i][j] = max(dp[i-1][j-w[i-1]] + v[i-1], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }

        }
    }
    printf("%lld\n", dp[N][W]);
    return 0;
}
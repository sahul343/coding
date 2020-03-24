#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int a[n][3];
    for(int i = 0; i < n; i++){
        scanf("%d %d %d",&a[i][0], &a[i][1], &a[i][2]);
    }
    int dp[n][3];
    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];
    for(int i = 1; i < n; i++){
        for(int j = 0; j < 3; j++){
            dp[i][j] = a[i][j] + max(dp[i-1][(j+1)%3],dp[i-1][(j + 2)%3]);
        }
    }
    printf("%d\n",max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2])));
    return 0;
}
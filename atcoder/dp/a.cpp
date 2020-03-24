#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int a[n+1];
    for(int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
    }
    a[0] = a[1];
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 0;
    for(int i = 2; i <= n; i++){
        dp[i] = min(dp[i-2] + abs(a[i] - a[i-2]), dp[i-1] + abs(a[i] - a[i-1]));
    }
    printf("%d\n",dp[n]);
    return 0;
}
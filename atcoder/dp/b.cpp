#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n+1];
    for(int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
    }
    a[0] = a[1];
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 0;
    for(int i = 2; i <= n; i++){
        int ans = INT_MAX;
        for(int j = i - 1; j >= max((i - k),0); j--){
            ans = min(ans, dp[j] + abs(a[j] - a[i]));
        }
        dp[i] = ans;
    }
    printf("%d\n",dp[n]);
    return 0;
}
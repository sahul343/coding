#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int mod = 1e9 + 7;
    scanf("%d", &n);
    vector<int>a[n];
    int x;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&x);
            if(x == 1){
                a[i].push_back(j);
            }
        }
    }
    int m = (1 << n);
    int dp[m];
    memset(dp, 0,sizeof(dp));
    for(int i = 0; i < a[0].size(); i++){
        dp[(1 << a[0][i])] = 1;
    }
    for(int i = 1; i < n; i++){
        for(int j = m - 1; j > 0; j--){
            if(__builtin_popcount(j) == i + 1){
                for(int k = 0; k < a[i].size(); k++){
                    if(j & (1 << a[i][k])){
                        dp[j] = (dp[j] + dp[j - (1 << a[i][k])]) % mod;
                    }
                }
            }
        }
    }
    printf("%d\n",dp[m - 1]);
    return 0;
}  
#include<bits/stdc++.h>
using namespace std;
long long solve(vector<vector<long long> >&dp,int N,int W, int *w,int *v){
    if(N == 0 || W == 0) return 0;
    if(dp[N][W] != -1) return dp[N][W];
    long long a1, a2;
    if(W >= w[N-1]){
        dp[N][W] = max(v[N-1] + solve(dp, N-1, W-w[N-1],w,v), solve(dp, N-1, W, w, v) );
    }
    else{
        dp[N][W] = solve(dp, N-1, W, w, v);
    }
    return dp[N][W];
}
int main(){
    int N, W;
    scanf("%d %d",&N, &W);
    int w[N], v[N];
    for(int i = 0; i < N; i++){
        scanf("%d %d",&w[i], &v[i]);
    }
    vector<vector<long long> > dp(N+1, vector<long long>(W+1, -1));
    solve(dp, N, W, w, v);
    printf("%lld\n", dp[N][W]);
    return 0;
}
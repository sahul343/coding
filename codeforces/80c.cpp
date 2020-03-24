#include<bits/stdc++.h>
using namespace std;
int m1 = 1e9+7;
int solve(vector<vector<int> > & dp, int n, int m){
    if(m == 0)return 0;
    if(n == 0)return 0;
    if(m == 1)return n;
    if(n == 1)return 1;
    if(dp[n][m] != -1)return dp[n][m];
    long long ans = 0;
    for(int i = n; i >= 1; i--){
        ans += solve(dp, i, m-1 );
        ans = ans%m1;
    }
    dp[n][m] = ans;
    return ans;

}
int main(){
    long long n, m;
    cin >> n >> m;
    int l = 2*m;
    vector<vector<int>>dp(n+1, vector<int>(l+1, -1));
    cout << solve(dp, n, l) << endl;
    return 0;
}
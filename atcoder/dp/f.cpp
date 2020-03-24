#include<bits/stdc++.h>
using namespace std;
int main(){
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++)
        dp[i][m] = 0;
    for(int i = 0; i < m; i++)
        dp[n][i] = 0;
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            if(s[i] == t[j]) {
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else {
                dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    //cout << dp[0][0] << endl;
    int i = 0, j = 0;
    string ans;
    while( i < n && j < m){
        if(s[i] == t[j]) {
            ans.push_back(s[i]);
            i++, j++;
        }
        else if(dp[i+1][j] >= dp[i][j+1]){
            i++;
        }
        else{
            j++;
        }
    }
    cout << ans << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int n;
    cin >> n;
    vector<double>p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    vector<vector<double> > dp(n, vector<double>(n+1, 0));
    dp[0][0] = 1-p[0];
    dp[0][1] = p[0];
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i+1; j++){
            dp[i][j] = dp[i-1][j] * (1 - p[i]);
            if( j > 0)
            dp[i][j] += dp[i-1][j-1] * p[i];
        }
    }
    double ans = 0;
    for(int j = n/2+1 ; j <= n; j++){
        ans += dp[n-1][j];
    }
    cout << fixed;
    cout << setprecision(10);
    cout << ans << endl;
    return 0;
}
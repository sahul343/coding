#include<bits/stdc++.h>
using namespace std;
int m1 = 1e9+7;

int main(){
    long long n, m;
    cin >> n >> m;
    int l = 2*m;
    vector<vector<int>>dp(n+1, vector<int>(l+1, 0));
    for(int i = 1; i <= n;  i++){
        for(int j = 1; j <= l ; j++){
            if(j == 1){
                dp[i][j] = i;
                continue;
            }
            if(i == 1){
                dp[i][j] = 1;
                continue;
            }
            long long curr = 0;
            for(int k = i; k >=0 ; k--){
                curr += dp[k][j-1];
                curr = curr%m1;
            }
            dp[i][j] = curr;
        }
    }
    cout << dp[n][l] << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    int dp[201][201][201]; 
    memset(dp, -1, sizeof(dp));
    dp[0][1][0] = 0;
    dp[0][0][0] = 1;
    dp[0][0][0] = 2;
    for(int i = 1; i <= 200; i++){
        for(int j = 1; j <= 200; j++){
            for(int k = 1; k <= 200; k++){
               if(i + j + k <= 5){
                   dp[i][j][k] = 0;
               }
               else{
                   if(dp[i-1][j][k] == 2 || dp[i][j-1][k] == 2 || dp[i][j][k-1] == 2){
                       dp[i][j][k] = 0;
                   }
                   else if(dp[i-1][j][k] == 0 || dp[i][j-1][k] == 0 || dp[i][j][k-1] == 0){
                       dp[i][j][k] = 1;
                   }
                   else{
                       dp[i][j][k] = 2;
                   }
               }
            }
        }
    }
    while( t -- ){
        // cout <<"Came here\n";
        int c1, c2, c3;
        cin >> c1 >> c2 >> c3;
        if(dp[c1][c2][c3] == 0){
            cout << "Santhosh\n";
        }
        else if(dp[c1][c2][c3] == 1){
            cout << "Ahmed\n";
        }
        else{
            cout << "Rakesh\n";
        }
        
    }
    return 0;
}
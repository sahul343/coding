#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<int>dp(k+1, 2);
    sort(a, a+n);
    for(int i = 1; i <= k ;i++){
        int j = 0;
        while(j<n && a[j] <= i){
            if(dp[i-a[j]] == 2){
                dp[i] = 1;
                break;
            }
            j ++;
        }
    }
    if(dp[k] == 1){
        cout << "First\n";
    }
    else{
        cout << "Second\n";
    }
    return 0;
}
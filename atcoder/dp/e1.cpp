#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, w;
    cin >> n >> w;
    int v = 1e5;
    vector<long long>dp(v + 1, INT_MAX);
    dp[0] = 0;
    int weight, value;
    for(int i = 0; i < n; i++){
        cin >> weight >> value;
        for(int j = v-value; j >= 0; j--){
            dp[j+value] = min(dp[j+value], dp[j] + weight );
        }
    }
    for(int i = v; i >= 0; i--){
        if(dp[i] <= w){
            cout << i << endl;
            break;
        }
    }
    return 0;
}
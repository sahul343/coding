#include<bits/stdc++.h>
using namespace std;
int main(){
    //cout << "notstartred";
    int n;
    //cout << "start\n";
    cin >> n;
    int a[n];
    int cnt[3];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i] - 1] ++;
    }
    //cout << "seg\n";
    double dp[310][310][310];
    memset(dp, 0, sizeof(dp));
    for(int k = 0; k <= n; k ++){
        for(int j = 0; j + k <= n; j++){
            for(int i = 0; i + j + k <= n; i++){
                if( i + j + k == 0) continue;
                double wait = 1.0 * n/(i + j + k);
                double p1 = 1.0 * i/(i + j + k);
                double p2 = 1.0 * j/(i + j + k);
                double p3 = 1.0 * k/(i + j + k);
                if(i)
                    dp[i][j][k] += p1 * dp[i - 1][j][k];
                if(j)
                    dp[i][j][k] += p2 * dp[i + 1][j - 1][k];
                if(k)
                    dp[i][j][k] += p3 * dp[i][j + 1][k - 1];
                dp[i][j][k] += wait;
            }
        }
    }
    cout << setprecision(10);
    cout << dp[cnt[0]][cnt[1]][cnt[2]] << "\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int a[n], t[n];
    int sum[n+1], actsum[n+1];
    memset(sum, 0, sizeof(sum));
    memset(actsum, 0, sizeof(actsum));
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum[i+1]  += sum[i] + a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> t[i];
        actsum[i + 1] = actsum[i];
        if(t[i] == 1){
            actsum[i+1] += a[i];
        }
    }
    int ans = 0;
    for(int i = 1; i <= n - k + 1; i++){
        ans = max(ans, actsum[i-1]  + (actsum[n] - actsum[i+k-1])+ (sum[i+k-1]- sum[i-1]));
    }
    cout << ans << endl;
    return 0;
}
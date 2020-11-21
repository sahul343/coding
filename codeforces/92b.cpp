#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t --){
       int n, k, z;
       cin >> n >> k >> z;
       int a[n];
       int ans = 0;
       vector<int>stunt(n, 0);
       vector<int>cumsum(n, 0);
       for(int i = 0; i < n; i ++){
            cin >> a[i];
            if(i != 0){
                stunt[i] = a[i] + a[i - 1];
                cumsum[i] = cumsum[i - 1] + a[i];
            }
            else{
                cumsum[i] = a[i];
            }
       }
       ans = cumsum[k];
       //cout << ans << "\n";
       if(z == 0 || k == 1){
           cout << ans << "\n";
       }
       else if(z >= 1){
            if(z >= 1){
                for(int i = 0; i <= (k - 2); i ++){
                    ans = max(ans, cumsum[k - 2] + stunt[i + 1]);
                }
            }
           // cout << ans << "\n";
            if(z >= 2 && k >= 4){
                for(int i = 0; i < (k - 4); i ++){
                    ans = max(ans, cumsum[k - 4] + 2 * stunt[i + 1]);
                }
                for(int i = 1; i <= (k - 4); i ++){
                    ans = max(ans, cumsum[k - 4] + stunt[i] + stunt[k -3]);
                    ans = max(ans, cumsum[k - 4] + 2 * stunt[k -3]);
                }
            }
           // cout << ans << "\n";
            if(z >= 3 && k >= 6){
                for(int i = 0; i < (k - 6); i ++){
                    ans = max(ans, cumsum[k - 6] + 3 * stunt[i + 1]);
                }
                for(int i = 1; i <= (k - 6); i ++){
                    ans = max(ans, cumsum[k - 6] + 2 * stunt[i] + stunt[k -5]);
                    ans = max(ans, cumsum[k - 6] + 1 * stunt[i] + 2 * stunt[k -5]);
                    ans = max(ans, cumsum[k - 6] +  3 * stunt[k -5]);
                }
            }
            if(z >= 4 && k >= 8){
                for(int i = 0; i < (k - 8); i ++){
                    ans = max(ans, cumsum[k - 8] + 4 * stunt[i + 1]);
                }
                for(int i = 1; i <= (k - 8); i ++){
                    ans = max(ans, cumsum[k - 8] + 3 * stunt[i] + stunt[k -7]);
                    ans = max(ans, cumsum[k - 8] + 2 * stunt[i] + 2 * stunt[k -7]);
                    ans = max(ans, cumsum[k - 8] + 1 * stunt[i] +  3 * stunt[k -7]);
                    ans = max(ans, cumsum[k - 8] + 0 * stunt[i] +  4 * stunt[k -7]);
                }
            }
            if(z >= 5 && k >= 10){
                for(int i = 0; i < (k - 10); i ++){
                    ans = max(ans, cumsum[k - 10] + 5 * stunt[i + 1]);
                }
                for(int i = 1; i <= (k - 10); i ++){
                    ans = max(ans, cumsum[k - 10] + 4 * stunt[i] + 1 * stunt[k -9]);
                    ans = max(ans, cumsum[k - 10] + 3 * stunt[i] + 2 * stunt[k -9]);
                    ans = max(ans, cumsum[k - 10] + 2 * stunt[i] + 3 * stunt[k -9]);
                    ans = max(ans, cumsum[k - 10] + 1 * stunt[i] + 4 * stunt[k -9]);
                    ans = max(ans, cumsum[k - 10] + 0 * stunt[i] + 5 * stunt[k -9]);
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
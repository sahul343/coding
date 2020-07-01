#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t --){
        int n;
        cin >> n;
        int a[n];
        int sum = 0;
        int ans = INT_MAX;  
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i] --;
            sum += a[i];
            ans = min(ans, sum);
            if(sum > 0){
                sum = 0;
            }
        }
        cout << ans << "\n";

    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t --){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i ++){
            cin >> a[i];
        }
        if(n == 1){
            cout << "1\n";
        }
        int mx = a[0];
        for(int i = 0; i < n; i ++){
            mx = max(mx, a[i]);
        }
        int ans = -1;
        for(int i = 0; i < n; i ++){
            if(a[i] != mx) continue;
            if(i == 0){
                if(a[i + 1] < a[i]){
                    ans = i + 1;
                }
            }
            else if(i == (n - 1)){
                if(a[i - 1] < a[i]){
                    ans = i + 1;
                }
            }
            else{
                if(a[i - 1] < a[i] || a[i + 1] < a[i]) {
                    ans = i + 1;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
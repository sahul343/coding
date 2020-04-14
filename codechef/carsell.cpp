#include<bits/stdc++.h>
using namespace std;
const int m = 1e9 + 7;
int main(){
    int t, n;
    cin >> t;
    while( t --){
        cin >> n;
        int a[n];
        for(int i = 0;  i < n; i++){
            cin >> a[i];
        }
        sort(a, a+n, greater<int>());
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans = (ans + max(0, a[i] - i))%m;
        }
        cout << ans << endl;
    }
    return 0;
}
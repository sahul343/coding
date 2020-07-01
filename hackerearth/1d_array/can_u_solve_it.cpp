#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while( t -- ){
        int n;
        cin >> n;
        int a;
        cin >> a;
        int mn1 = a;
        int mn2 = mn1, mx1 = mn1, mx2 = mn1;
        for(int i = 1; i < n; i ++){
            cin >> a;
            mn1 = min(mn1, a - i);
            mx1 = max(mx1, a - i);
            mn2 = min(mn2, a + i);
            mx2 = max(mx2, a + i);
        }
        int ans = max(abs(mx1 - mn1), abs(mx2 - mn2));
        cout << ans << endl;
    }
    return 0;
}
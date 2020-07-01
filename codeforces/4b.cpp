#include<bits/stdc++.h>
using namespace std;
int  main(){
    string s, r;
    cin >> s;
    int n = s.size();
    int a[n];
    int b[n];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    int cnt1 = 0, cnt2 = 0, f1 = 0, f2 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'v') {
            f1 ++;
            a[i] = cnt1 + f1 - 1;
        }
        else {
            cnt1 += max(0, f1 - 1);
            f1 = 0;
            a[i] = cnt1;
        }
        if(s[n-1-i] == 'v') {
            f2 ++;
            b[i] = cnt2 + f2 - 1;
        }
        else {
            cnt2 += max(0, f2 - 1);
            f2 = 0;
            b[i] = cnt2;
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'o'){
            ans += a[i] * 1ll * b[n - 1 - i];
        }
    }
    cout << ans << "\n";
    return 0;
}
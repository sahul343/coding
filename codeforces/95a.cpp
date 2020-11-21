#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t --){
        long long x, y, k;
        cin >> x >> y >> k;
        long long required = y * k + k;
        long long ans = (required - 1)/(x - 1) + k;
        if((required - 1) % (x - 1) != 0) ans ++;
        cout << ans << "\n";
    }
    return 0;
}
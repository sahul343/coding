#include<bits/stdc++.h>
using namespace std;
long long pow1(int a, int n){
    if( n < 0 ) return 0;
    long long ans = 1;
    for(int i = 0; i < n; i++){
        ans *= a;
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    long long ans = 1;
    ans = 2  * 4 * 3 * pow1(4, n - 3);
    ans += (n-3) * 4 * 3 * 3 * pow1(4, n - 4);
    cout << ans << endl;
    return 0;
}
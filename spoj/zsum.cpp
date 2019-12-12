#include<bits/stdc++.h>
using namespace std;
int m = 1e7+7;
int pow1(int n, int k){
    if(k==0) return 1;
    else if(k%2 == 0) return pow1((n*1ll*n)%m, k/2)%m;
    else return (pow1((n*1ll*n)%m, k/2)*1ll*n)%m;
}
int main(){
    while(1){
        int n,k;
        cin >> n >>k;
        if(n==0 && k==0) break;
        long long ans = pow1(n, n);
        ans = (ans + pow1(n, k) ) %m ;
        ans = (ans + pow1(n-1, n-1)) %m;
        ans = (ans + pow1(n-1, n-1)) %m;
        ans = (ans + pow1(n-1, k)) %m;
        ans = (ans + pow1(n-1, k)) %m;
        ans = (ans + m)%m;
        cout << ans << endl;
    }
    return 0;
}
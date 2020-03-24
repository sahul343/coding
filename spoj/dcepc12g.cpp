#include<bits/stdc++.h>
using namespace std;
int n = 1e7;
int m = 1e9+7;
int phi[10000005];
int cprime[10000005];
int factorial[10000005];
int f[10000005];
int g[10000005];
int mypow(int a, int b){
    int ans = 1;
    while(b){
        if(b&1) ans = (ans*1ll*a)%m;
        a = (a*1ll*a)%m;
        b /= 2;
    }
    return ans;
}
void solve(){
    memset(cprime, 0 , sizeof(cprime)/sizeof(int));
    memset(factorial, 1, sizeof(factorial)/sizeof(factorial));
    for(int i = 1; i <= n; i++) {
        phi[i] = i;
        factorial[i] = (factorial[i-1] * i)%m;
    }
    for(int i = 2; i <= n; i++){
        if( phi[i] == i){
            cprime[i] = 1;
            for(int j = i; j <= n; j += i){
                phi[j] /= i;
                phi[j] *= i - 1;
            }
        }
    }
    for(int i = 1; i <= n; i++){
       cprime[i] += cprime[i-1];
    }
    for(int i = 1; i <= n; i++){
        f[i] = max(0, cprime[i] - phi[i]);
        g[i] = mypow(phi[i], factorial[f[i]]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    int t;
    cin >> t;
    while( t-- ){
        int n;
        cin >> n;
        cout << g[n] <<"\n";
    }
    return 0;
}
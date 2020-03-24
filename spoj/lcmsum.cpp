#include<bits/stdc++.h>
using namespace std;
long long res[1000005];
long long phi[1000005];
long long n = 1000000;

void solve(){
    for(int i = 1; i <= n ; i ++){
        phi[i] = i;
        // res[i] = 0;
    }
    for(int i = 2; i <= n; i++){
        if(phi[i] == i){
            for(int j = i; j <= n; j += i){
                phi[j] /= i;
                phi[j] *= i - 1;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j += i){
            res[j] += i*phi[i];
        }
    }
}
int main(){
    long long t, n;
    cin >> t;
    memset(res, 0, sizeof(res)/sizeof(long long) );
    solve();
    while ( t -- ){
        cin >> n;
        cout << ( (res[n] + 1) * n ) / 2 << endl;
    }
    return 0;
}
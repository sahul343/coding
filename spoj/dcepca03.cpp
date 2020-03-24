#include<bits/stdc++.h>
using namespace std;
int phi[10005];
int sum[10005];
int n = 10000;
void solve(){
    for(int i = 1; i <=n; i++){
        phi[i] = i;
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
        sum[i] += sum[i-1] + phi[i];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(sum, 0, sizeof(sum)/sizeof(int));
    solve();
    int t;
    cin >> t;
    while( t-- ){
        int n ;
        cin >> n;
        cout << sum[n]*1ll*sum[n] << "\n";
    }
    return 0;
}
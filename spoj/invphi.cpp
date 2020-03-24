#include<bits/stdc++.h>
using namespace std;
int   phi[300000005];
int   ans[100000001];
int   n = 3e8;
void solve(){
    for(int i = 0; i <= 1e8; i++){
        ans[i] = -1;
    }
    for(int   i = 1; i <= n; i++){
        phi[i] = i;
    }
    for(int   i = 2; i <= n ; i++){
        if(phi[i] == i){
            for(int j = i; j <= n; j += i){
                phi[j] -= phi[j]/i;
            }
        }
    }
    for(int   i = 1; i <= n; i++){
       if(phi[i] <= 1e8  && ans[phi[i]] == -1){
           ans[phi[i]] = i;
       }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, x;
    cin >> t;
    solve();
    while( t-- ){
        cin >> x;
        cout << ans[x] <<"\n";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int  phi[100005];
long long ans[100005];
int n = 1e5;
void solve(){
    for(int i = 1; i <= n; i++){
        phi[i] = i;
        ans[i] = 0;
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
        ans[i] = ans[i-1] + i - phi[i];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        int n;
        cin >> n;
        cout <<"Case "<<i<<": "<<ans[n]<<"\n";
        // cout << phi[n] <<endl;
    }
    return 0;
}
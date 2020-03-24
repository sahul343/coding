#include<bits/stdc++.h>
using namespace std;
int phi[10000005];
int ans[10000005];
int n = 1e7;

bool is_permute(int x, int y){
    int digits[10];
    for(int i = 0; i <10; i++) digits[i] = 0;
    while(x){
        digits[x%10]++;
        x /= 10;
    }
    while(y){
        digits[y%10]--;
        y /= 10;
    }
    for(int i = 0; i < 10; i++){
        if(digits[i] != 0)return false;
    }
    return true;
}
void solve(){
    memset(ans, -1 , sizeof(ans)/sizeof(int));
    for(int i = 1; i <= n; i++){
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
    for(int i = 2; i <= n; i++){
        if(is_permute(i, phi[i])){
    
            if(ans[i-1] == -1 || i*1ll*phi[ans[i-1]] <= phi[i]*1ll*ans[i-1]){
                ans[i] = i;
            }
            else{
                ans[i] = ans[i-1];
            }
        }
        else
        {
            ans[i] = ans[i-1];
        }
        
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    solve();
    cin >> t;
    while( t-- ){
        int m;
        cin >> m;
        if(ans[m-1] == -1){
            printf("No solution.\n");
        }
        else{
            printf("%d\n",ans[m-1]);
        }
    }
    
    return 0;
}
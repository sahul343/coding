#include<bits/stdc++.h>
using namespace std;
long long phi[1000005];
long long gcdsum[1000005];
unsigned long long cum[1000005];
int n = 1e6;
void solve(){
    for(int i = 1; i <= n ; i++ ){
        phi[i] = i;
        gcdsum[i] = -i;
        cum[i] = 0;
    }
    for(int i = 2; i <= n ; i++){
        if(phi[i] == i){
            for(int j = i; j <= n; j += i){
                phi[j] /= i;
                phi[j] *= i - 1;
            }
        }
    }
    for(int i = 1; i <= n ; i++){
        for(int j = i; j <= n; j+= i){
            gcdsum[j] += i * phi[j/i];
        }
    }
    for(int i = 1; i <= n; i++){
        cum[i] += cum[i-1] + gcdsum[i];
    }
}
int main(){
    int n;
    solve();
    while(cin >> n){
        //compute ans for n and return the result
       if( n == 0)break;
       cout << cum[n] << endl;
    }
    return 0;
}
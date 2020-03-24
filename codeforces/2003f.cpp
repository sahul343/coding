#include<bits/stdc++.h>
using namespace std;
unsigned long long  totient(unsigned long long  n){
    unsigned long long  ans = n;
    for(unsigned long long  i = 2; i * i  <=n; i++){
        if(n%i == 0){
            while(n%i == 0){
                n /= i;
            }
            ans -= ans/i;
        }
    }
    if( n > 1){
        ans -= ans/n;
    }
    return ans;
}
unsigned long long  mypow(unsigned long long  n, unsigned long long  m){
    unsigned long long  a = 2;
    unsigned long long  ans = 1;
    while(n){
        if(n&1){
            ans = (ans*1ll*a)%m;
        }
        a = (a*1ll*a)%m;
        n /= 2;
    }
    return ans;

}
unsigned long long  solve(unsigned long long  n, unsigned long long  k){
    unsigned long long  phi_k = totient(k);
    unsigned long long  rem = mypow(n, phi_k);
    if(n >= log2(phi_k)){
        return mypow(phi_k + rem, k);
    }
    else{
        return mypow(pow(2,n),k);
    }
}
int main(){
    FILE *f1 = fopen("calc.in","r");
    FILE *f2 = fopen("calc.out","w");
    unsigned long long  n, k;
    fscanf(f1,"%llu %llu",&n,&k);
    
    if(n == 0){
        fprintf(f2,"%llu",3%k);
        return 0;
    }
    // cout << solve(n,k) << endl;
    unsigned long long  ans;
    if(k%2 == 0){
        ans = mypow( mypow(n, totient(k)), k);
    }
    else{
        ans = solve(n, k);
    }
    ans = (ans + 1)% k ;
    fprintf(f2,"%llu",ans);
   
    return 0;
}
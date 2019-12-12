#include<bits/stdc++.h>
using namespace std;
int m = 1e9+7;
long long pow1(long long a, long long n){
    if(n == 0)return 1;
    else if (n%2 == 0) return (pow1((a*a)%m, n/2))%m;
    else return ( pow1((a*a)%m, n/2) * a ) %m;
}
long long solve(long long n){
    long long ans = 1;
    
    if(n%3 == 0)
        ans =  pow1(3,n/3);
    else if (n%3 == 1)
        ans = 4 * pow1(3, (n-4)/3);
    else
        ans = 2 * pow1(3, (n-2)/3);
    

    return ans%m;
}
int main(){
    int t;
    cin >>t;
   // cout << m << endl;
    while( t-- ){
        long long n;
        cin >> n;
        if(n <= 3) cout << n <<endl;
        else cout << solve(n) << endl;
    }
    return 0;
}
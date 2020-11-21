#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long ans = 1;
    for(int i = 1; i <= n/2; i ++){
        ans = (ans * (n - (i - 1)))/i;
    }
    long long fact = 1;
    for(int i = 1; i <= (n/2 - 1); i ++){
        fact = fact * i;
    }
    ans = (ans * fact * fact)/2;
    cout << ans << "\n";
    return 0;
}
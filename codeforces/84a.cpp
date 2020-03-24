#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        unsigned long long n,k;
        cin >> n >> k;
        if(n >= k*k && n%2 == k%2) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
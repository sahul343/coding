#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin >> t;
    while( t-- ){
        ll n;
        cin >> n;
        int ans = 0;
        for(ll k = 5; k <= n; k *= 5){
            ans += n/k;
        }
        cout << ans << "\n";
    }
    return 0;
}
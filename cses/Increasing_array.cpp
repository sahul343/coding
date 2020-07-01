#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int x;
    cin >> x;
    int mx = x;
    long long ans = 0;
    for(int i = 0; i < n - 1 ; i ++){
        cin >> x;
        if( x < mx){
            ans += mx - x;
        }
        else{
            mx = x;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
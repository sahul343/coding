#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t --){
        unsigned long long n, r;
        cin >> n >> r;
        unsigned long long ans = 0;
        if(n > r){
            ans = (r * (r + 1))/2;
        }
        else if(n == r){
          ans = 1 + (r * (r - 1))/2;
        }
        else{
            ans = 1 + (n * (n - 1))/2;
        }
        cout << ans << "\n";
    }
    return 0;
}
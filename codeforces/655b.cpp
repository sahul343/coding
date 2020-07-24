#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t --){
        int n;
        cin >> n;
        long long ans = n - 1;
        long long a = 1, b = n - 1;
        for(int i = sqrt(n); i >= 1; i --){
            if(n%i == 0){
                long long d1 = i, d2 = n/i;
                long long x1 = d1, y1 = n - d1;
                long long x2 = d2, y2 = n - d2;
                if(x1 > 0 && y1 > 0){
                   int ans1 = (x1 * y1)/d1;
                   if(ans1 < ans){
                       ans = ans1;
                       a = x1, b = y1;
                   }
                }
                if(x2 > 0 && y2 > 0){
                    int ans2 = (x2* y2)/d2;
                    if(ans2 < ans){
                        ans = ans2;
                        a = x2, b = y2;
                    }
                }
            }
        }
        cout << a << " " << b << "\n";
    }
    return 0;
}
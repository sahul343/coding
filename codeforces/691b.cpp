#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int ans = 0;
    if(n == 1) {
        cout << "4\n";
        return 0;
    }
    else if(n == 2) {
        cout << "4\n";
        return 0;
    }
    else if(n == 3) {
        cout << "12\n";
        return 0;
    }
    for(int i = -n; i <= n; i ++){
        for(int j = -n; j <= n; j ++){
            if(abs(i) + abs(j) > n) continue;
            if(abs(i) <= (n + 1)/2 && (abs(j) <= (n + 1)/2) ){
                int x = abs(i), y = abs(j);
                int steps = x + y;
                if(steps <= n){
                    if( (abs(x - y) <= 1 && (n - steps)%4 == 0)) {
                        // cout << i << " " << j << "\n";
                        ans ++;
                    }
                    else {
                        //int steps1 = steps + (abs(x - y)) * 2;
                        if(abs(x - y) >= 1 && steps <= n && (n - steps)%2 == 0) {
                            // cout << i << " " <<  j << "\n";
                            ans ++;
                        }
                    }
                }
                // if( n < 4 || ( n >= 4 && (n - abs(i) - abs(j))%4 == 0)){
                   
                // }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
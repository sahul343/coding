#include<bits/stdc++.h>
using namespace std;
int calculate(int k, int n){
    int steps = (k - 1);
    n = n - k;
    if(n%k == 0) {
        steps += n/k;
    }
    else{
        steps += (n/k + 1);
    }
    return steps;
}
int main(){
    int t;
    cin >> t;
    while( t --){
        int n;
        cin >> n;
        int ans = n;
        int low = sqrt(n) - 1000, high = sqrt(n) + 1000;
        low = max(low, 1);
        high = min(high, n);
        for(int i = low; i <= high; i ++){
            ans = min(ans, calculate(i, n));
        }
        cout << ans << "\n";
    }
    return 0;
}
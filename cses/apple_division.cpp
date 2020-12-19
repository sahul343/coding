#include<bits/stdc++.h>
using namespace std;
void calculate(long long* a, long long n, long long idx, long long &sum, long long &ans, long long &currsum){
    if(currsum > 0 && currsum < sum){
        ans = min(ans, abs(sum - 2 * currsum));
        
    }
    for(long long i = idx; i < n; i ++){
        currsum += a[i];
        calculate(a, n, i + 1, sum, ans, currsum);
        currsum -= a[i];
    }
}
int main(){
    long long n;
    cin >> n;
    long long a[n];
    long long sum = 0;
    for(long long i = 0; i < n; i ++){
        cin >> a[i];
        sum += a[i];
    }
    long long ans = sum;
    long long currsum = 0;
    calculate(a, n, 0, sum, ans, currsum);
    cout << ans << "\n";
    return 0;
}
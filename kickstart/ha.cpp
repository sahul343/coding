#include<bits/stdc++.h>
using namespace std;
long long solve(){
    long long n, k, s;
    cin >> n >> k >> s;
    long long ans = k + n;
    ans = min((n - s + 1) + (k - 1) + (k - s), ans);
    return ans;
}
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i ++){
        cout << "Case #"<<i << ": " << (solve()) << "\n";
    }
    return 0;
}
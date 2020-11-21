#include<bits/stdc++.h>
using namespace std;
long long solve (){
    int n;
    cin >> n;
    int x;
    long long ans = 0;
    map<int, long long>m;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            cin >> x;
            m[j - i] += x;
            ans = max(ans, m[j - i]);
        }
    }
    return ans;
}
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i ++){
        long long cnt = solve();
        cout << "Case #" << i << ": ";
        cout << cnt << "\n";
    }
    return 0;
}
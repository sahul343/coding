#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    long long ans = 0;
    sort(a, a + n, greater<int>());
    for(int i = 0; i < n; i++){
        ans = max(ans, (i + 1)*a[i]);
    }
    cout << ans << "\n";
    return 0;
}
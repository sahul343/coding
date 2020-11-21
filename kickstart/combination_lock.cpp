#include<bits/stdc++.h>
using namespace std;
long long solve (){
    int w, n;
    cin >> w >> n;
    int a[w];
    for(int i = 0; i < w; i ++){
        cin >> a[i];
    }
    long long ans = LONG_LONG_MAX;
    //cout << w << "\n";
    for(int i = 0; i < w; i ++){
        long long curr = 0;
        for(int j = 0; j < w; j ++){
            curr += min(abs(a[i] - a[j]), n - abs(a[i]- a[j]));
        }
        //cout << i << " " << curr << "\n";
        ans = min(ans, curr);
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
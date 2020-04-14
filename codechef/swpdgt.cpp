#include<bits/stdc++.h>
using namespace std;
int p[3] = {1, 10 , 100};
int main(){
    int t;
    cin >> t;
    while( t-- ){
        int x, y;
        cin >> x  >> y;
        string a = to_string(x), b = to_string(y);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n = a.size();
        int m = b.size();
        int ans = x + y;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, x + y + (b[j] - a[i]) * p[i]+ int((a[i] - b[j]) * p[j]));
            }
        }
        cout << ans << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}
int main(){
    int t;
    cin >> t;
    while( t -- ){
        string s;
        cin >> s;
        int m;
        cin >> m;
        int b[m];
        for(int i = 0; i < m; i ++){
            cin >> b[i];
        }

    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int k = 1; k <= t; k ++){
        int n;
        cin >> n;
        vector<pair<int, int>>timber(n);
        for(int i = 0; i < n; i ++){
            cin >> timber[i].first >> timber[i].second;
        }
        map<long long, long long>m;
        sort(timber.begin(), timber.end());
        long long ans = 0;
        for(int i = 0; i < n; i ++){
           long long pos = timber[i].first, height = timber[i].second;
           long long left = max(m[pos], m[pos - height] + height);
           long long right = max(m[pos + height], m[pos] + height);
           m[pos] = left;
           m[pos + height] = right;
           ans = max(ans, m[pos]);
           ans = max(ans, m[pos + height]);
        }
        cout << "Case #" << k << ": " << ans << "\n";
    }
    
    return 0;
}
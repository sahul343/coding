#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t -- ){
        int n;
        cin >> n;
        int a[n];
        int cnt = 0;
        vector<int>pos;
        for(int i = 0; i < n; i ++){
            cin >> a[i];
            cnt += a[i];
            if(a[i] == 1) pos.push_back(i);
        }

        if(cnt == n){
            cout << "0\n";
        }
        else{
            int ans = 0;
            int m = pos.size();
            for(int i = 1; i < m; i ++){
                ans += (pos[i] - (pos[i - 1] + 1) );
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
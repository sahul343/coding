#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    int f[200001];
    while( t --){
        int n;
        cin >> n;
        int a[n];
        memset(f, 0, sizeof(f));
        bool flag = true;
        int max_num = 0;
        int mx_1 = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            f[a[i]] ++;
            if(f[a[i]] > 2){
                flag = false;
            }
            if(f[a[i]] == 2){
                max_num = max(max_num, a[i]);
            }
        }
        for(int i = 1; i <= max_num; i++){
            if(f[i] != 2){
                flag = false;
                break;
            }
        }
        for(int i = max_num + 1; )
        if(flag == false){
            cout << "0\n";
            continue;
        }
        memset(f, 0, sizeof(f));
        vector<int>ans;
        int mx = a[0];
        f[a[0]] ++;
        for(int i = 1; i < n; i++){
            if(mx == i){
                ans.push_back(i);
            }
            if(f[a[i]] == 1) break;
            f[a[i]] ++;
            mx = max(a[i], mx);
        }
        cout << ans.size() << "\n";
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " " << n - ans[i] << "\n";
        }
    }
    return 0;
}
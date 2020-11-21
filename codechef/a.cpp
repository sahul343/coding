#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, q;
    cin >> n >> q;
    int a[n];
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    int cnt = 1;
    for(int i = 1; i < n; i ++){
        if(a[i] == a[i - 1]) continue;
        cnt ++;
    }
    for(int i = 0; i < q; i ++){
        int idx, value;
        cin >> idx >> value;
        idx --;
        int left = (idx > 0)?a[idx - 1]:INT_MAX;
        int right = (idx < (n - 1))?a[idx + 1]:INT_MIN;

        if(a[idx] == left || a[idx] == right){
            if(value != left && value != right) cnt ++;
        }
        else{
            if(value == left && value == right) {
                cnt -= 2;
            }
            else if(value == left || value == right) cnt --;
        }

        cout << cnt << "\n";
    }
}
int main(){
    int t;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}
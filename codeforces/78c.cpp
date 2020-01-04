#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t-- ){
        int n;
        cin >> n;
        vector<int>a(2*n);
        for(int i = 0; i < 2*n; i++){
            cin >> a[i];
        }
        int start = 0;
        int ans = 2*n;
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
        m1[0] = -1;
        m2[0] = 2*n;
        for(int i = 0; i < n; i++){
            if(a[i] == 1){
                start++;
            }
            else {
                start--;
            }
            m1[start] = i;
            if(m2.find(-start) != m2.end()){
                ans = min(ans,m2[0-start]-i-1);
            }
        }
        int end = 0;
        for(int i = 2*n-1; i>=n ; i--){
            if(a[i] == 1){
               end++;
            }
            else{
               end--;
            }
            if(m1.find(0-end) != m1.end()){
                ans = min(ans, i-m1[0-end]-1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t-- ){
        int m1, n;
        cin >> n >> m1;
        int a[n];
        unordered_map<int,int>m;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            m[a[i]] = i;
        }
        int b[m1];
        int till_now = 0;
        long long ans  = 0;
        for(int i = 0; i < m1; i++){
            cin >> b[i];
            if(till_now >= m[b[i]]) ans++;
            else{
                till_now = m[b[i]];
                ans += 2*(m[b[i]]-i)+1;
            }
           // cout << ans << endl;
        }
        cout << ans << endl;


    }
    return  0;
}
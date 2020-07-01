#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, n, k;
    string s;
    cin >> t;
    while( t-- ){
         cin >> n >> k;
         cin >> s;
         int m = n/k;
         int start = 0, end = k - 1;
         int ans = 0;
         int f[26];
         while(start <= end){
            memset(f, 0, sizeof(f));
            for(int i = 0; i < m; i++){
                f[s[start + i * k] - 'a'] ++;
                if(start != end){
                    f[s[end + i * k] - 'a'] ++;
                }
            }
            start ++;
            end --;
            sort(f, f + 26);
            for(int j = 0; j < 25; j++){
                ans += f[j];
            }
         }
         cout << ans << "\n";
    }
    return 0;
}
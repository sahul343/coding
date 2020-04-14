#include<bits/stdc++.h>
using namespace std;
const int m = 1 << 20;
int dp[m];
void process(int curr, int pen_no){
    if(curr == 0) return;
    if(dp[curr] != -1) return;
    dp[curr] = pen_no;
 //   cout << curr << endl;
    for(int i = 0; i < 20; i++){
        if(curr & (1 << i)){
            process(curr ^ (1 << i), pen_no);
        }
    }
    return ;
}
int main(){
    int t, n, k;
    string s, curr;
    cin >> t;
    while( t --){
        memset(dp, -1, sizeof(dp));
        cin >> n >> k;
        cin >> s;
        for(int i = 0; i < k; i++){
            cin >> curr;
            int mask_curr = 0;
            for(int j = 0; j < curr.size(); j++){
                mask_curr |= (1 << (curr[j] - 'a'));
            }
           // cout << mask_curr << endl;
            process(mask_curr, i + 1);
        }
        int curr = 0;
        int prev = 0;
        for(int i = 0; i < n; i++){
            curr = curr | (1 << (s[i] - 'a'))   ;
            // cout << "at iteration ";
            // cout << i << " " << curr << endl;
            if(dp[curr] == -1){
                curr = curr ^ (1 << (s[i] - 'a'));
                // cout << "at allocation ";
                // cout << i << " " << curr << endl;
                for(int j = prev; j < i; j++){
                    cout << dp[curr]  << " ";
                }
                curr =  (1 << (s[i] - 'a')) ;
                prev = i;
            }
        }
       // cout << curr << endl;
        for(int i = prev; i < n; i++){
            cout << dp[curr] << " ";
        }
        cout << "\n";
    }
    return 0;
}
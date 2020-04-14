#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int k, x;
        cin >> k >> x;
        int fre[26];
        memset(fre, 0, sizeof(fre));
        int i = 0;
        int neg = 0;
        for(i = 0; i < s.size(); i++){
            fre[s[i] - 'a'] ++;
            if(fre[s[i] - 'a'] > x) {
                if( k <= 0) break;
                neg ++;
                k --;
                fre[s[i] - 'a'] --;  
            }
        }
        cout << i - neg << endl;
    }
    return 0;
}
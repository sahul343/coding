#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, depth = 0;
    cin >> t;
    string s;
    for(int k = 1; k <= t; k++){
        depth = 0;
        cin >> s;
        int n = s.size();
        string ans;
        for(int i = 0; i < n; i++){
            int required = (s[i] - '0');
            while(required < depth){
                ans.push_back(')');
                depth --;
            }
            while(required  > depth){
                ans.push_back('(');
                depth ++;
            }
            ans.push_back(s[i]);
        }
        while(depth > 0){
            ans.push_back(')');
            depth --;
        }
        cout << "Case #" << k << ": " << ans << "\n";
    }
    return 0;
}
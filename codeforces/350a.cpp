#include<bits/stdc++.h>
using namespace std;
int main(){
    int f[26];
    memset(f, 0, sizeof(f));
    int ans = 0;
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < (2 * n - 2); i += 2){
        f[s[i] - 'a' ] ++;
        if(f[s[i + 1] - 'A'] > 0){
            f[s[i + 1] - 'A'] --;
        }
        else ans ++;
    }
    cout << ans << "\n";
    return 0;
}
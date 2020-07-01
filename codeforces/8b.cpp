#include<bits/stdc++.h>
using namespace std;
int main(){
    char s[300005];
    scanf("%s",s);
    long long ans = 0;
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        if( (s[i]-'0') % 4 == 0) ans ++;
    }
    for(int i = 0; i < n - 1; i ++){
        if( ((s[i] - '0')*10 + (s[i+1] - '0')) % 4 == 0){
            ans += i + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
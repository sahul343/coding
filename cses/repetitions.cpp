#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    int ans = 1, curr_frequency = 1;
    for(int i = 0; i < n - 1; i ++){
        if(s[i] == s[i + 1]){
            curr_frequency ++;
        }
        else{
            curr_frequency = 1;
        }
        ans = max(ans, curr_frequency);
    }
    printf("%d\n", ans);
    return 0;
}
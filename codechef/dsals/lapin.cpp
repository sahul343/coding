#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    string s;
    int f[26];
    cin >> t;
    while( t --){
        cin >> s;
        memset(f, 0, sizeof(f));
        int start = 0, end = s.size() - 1;
        while(start < end){
            f[s[start] - 'a'] ++;
            f[s[end] - 'a'] --;
            start ++;
            end --;
        }
        int i = 0;
        for( i = 0; i < 26; i++){
            if(f[i] != 0) break;
        }
        if(i == 26){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
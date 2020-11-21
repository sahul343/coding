#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i ++){
       int n; cin >> n;
       string s; cin >> s;
       int cnt_a = 0, cnt_b = 0;
       for(char c: s){
           if(c == 'A') cnt_a ++;
           else cnt_b ++;
       }
       if(abs(cnt_a - cnt_b) == 1){
           cout << "Case #"<<i<<": "<<"Y\n";
       }
       else{
           cout << "Case #"<<i<<": "<<"N\n";
       }
    }
    return 0;
}
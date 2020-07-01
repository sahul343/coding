#include<bits/stdc++.h>
using namespace std;
bool match_5(string s){
    if(s == "ahmed" || s=="shiva") return true;
    else return false;
}
bool match_6(string s){
    if(s == "rakesh") return true;
    else return false;
}
int main(){
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 0; i <= n - 5; i++){
        if(match_5(s.substr(i, 5))){
            i += 4;
            ans ++;
        }
        else if( i + 6 <= n && match_6(s.substr(i, 6))){
            i += 5;
            ans ++;
        }
    }
    cout << ans << "\n";
    return 0;
}
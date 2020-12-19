#include<bits/stdc++.h>
using namespace std;
bool isexistshelper(string &s, string &pattern){
    if(pattern.size() == 0 || s.size() == 0) return false;
    int i = 0, j = 0;
    int n = s.size(), m = pattern.size();
    while(i < n && j < m){
        if(pattern[j] == s[i]){
            j ++;
        }
        i ++;
    }
    return j == m;
}
bool isexists(string &s, string &pattern){
    int n = s.size(), m = pattern.size();
    for(int i = 0; i < (n - 1); i ++){
        for(int j = 0; j < (m - 1); j ++){
            string s1 = s.substr(0, i + 1);
            string s2 = s.substr(i + 2, n);
            string p1 = pattern.substr(0, j + 1);
            string p2 = pattern.substr(j + 1, m);
            if(isexistshelper(s1, p1) && isexistshelper(s2, p2)) return true;
        }
    }
    return false;
}
void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int l, r;
    string pattern;
    for(int i = 0; i < q; i ++){
        cin >> l >> r;
        l --, r --;
        pattern = s.substr(l, (r - l + 1));
        if(isexists(s, pattern)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}
int main(){
    int t;
    cin >> t;
    while( t --){
        solve();
    }
    return 0;
}
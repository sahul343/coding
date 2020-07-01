#include<bits/stdc++.h>
using namespace std;
string solve(vector<string>&s){
    int n = s.size();
    int len[n];
    string ans;
    int mx = 0;
    int mx_index = 0;
    for(int i = 0; i < n ;i++){
        int curr = s[i].size();
        len[i] =  curr;
        if(curr > mx){
            mx = curr;
            mx_index = i;
        }
    }
    for(int j = 0; j < mx; j++){
        for(int i = 0; i < n; i++){
            // cout << j << endl;
            if( j < len[i] && s[i][j] != s[mx_index][j]) 
                return "*";
        }
    }
    return s[mx_index];
}
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        int n;
        cin >> n;
        vector<string>p(n);
        for(int j = 0; j < n; j++){
            cin >> p[j];
        }
        string start;
        vector<string>prefix(n);
        vector<string>suffix(n);
       // cout << "Ch1";
        for(int j = 0; j < n; j++){
            int k = 0;
            int len = p[j].size();
            for( k = 0; k < len; k++){
                if(p[j][k] == '*'){
                    break;
                }
                prefix[j].push_back(p[j][k]);
            }
            // string rem = p[j].substr(k + 1,p[j].size());
            // reverse(rem.begin(), rem.end());
            // suffix[j]  = rem;
            // prefix[j] = p[j].substr(0, k);
            for(int m = len - 1; m > k; m --){
                suffix[j].push_back(p[j][m]);
            }
        }
        string left = solve(prefix);
        string right = solve(suffix);
       // cout << "ch3";
        if(left == "*" || right == "*"){
            cout << "Case #"<<i<<": *\n";
        }
        else{
            reverse(right.begin(), right.end());
            cout << "Case #"<<i<<": "<<(left + right)<<"\n";
        }
    }
    return 0;
}
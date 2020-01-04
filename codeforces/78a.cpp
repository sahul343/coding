#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while( t-- ){
        string p, h;
        cin >> p >> h;
        vector<int> f1(26,0);
        for(int i = 0; i < p.size(); i++){
            f1[p[i] - 'a']++;
        }
        int flag = 0;
        int n = p.size();
        sort(p.begin(),p.end());
        for(int i = 0; i < h.size(); i++){
           string s = h.substr(i, n);
           sort(s.begin(),s.end());
           if( s == p) flag = 1;
        }
        if(flag == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
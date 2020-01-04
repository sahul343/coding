#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t-- ){
        string s, c;
        cin >> s >> c;
        int n = s.size();
        string s1 = s;
        sort(s1.begin(), s1.end());
        int i = 0;
        while( i < n && s1[i] == s[i]) i++;

        for(int j = n-1; j >= i+1 ; j--){
            if(s[j] == s1[i]){
                swap(s[i], s[j]);
                break;
            }
        }
        if(s < c)  cout << s << endl;
        else cout << "---" << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        if(s[n-2] == 'p' && s[n-1] == 'o') {
            cout << "FILIPINO" << endl;
        }
        else if(s[n-4] == 'm' && s[n-3] == 'a' && s[n-2] == 's' && s[n-1] == 'u'){
            cout << "JAPANESE" << endl;
        }
        else if(s[n-4] == 'd' && s[n-3] == 'e' && s[n-2] == 's' && s[n-1] == 'u'){
            cout << "JAPANESE" << endl;
        }
        else {
            cout << "KOREAN" << endl;
        }
    }
    return 0;
}
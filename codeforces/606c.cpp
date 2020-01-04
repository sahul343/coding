#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        vector<int>rem;
        int n = s.size();
        for(int i = 0; i < n - 2; i++){
            //cout << s << endl;
            if(i+4 < n){
                if(s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o' && s[i+3] == 'n' && s[i+4] == 'e' ){
                //cout << s.substr(i,5);
                s[i+2] = 'a';
                rem.push_back(i+3);
                }

            }
            if(s[i] == 'o' && s[i+1] == 'n' && s[i+2] == 'e'){
                //cout << s.substr(i,3) <<endl;
                 s[i+1] = 'a';
                 //cout << 2 << endl;
                 rem.push_back(i+2);
                 continue;
            }
            if(s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o'){
                //cout << s.substr(i,3) << endl;
                s[i+1] = 'a';
                rem.push_back(i+2);
            }
            
        }
        cout << rem.size() << endl;
        for(int i = 0; i< rem.size(); i++){
            cout << rem[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
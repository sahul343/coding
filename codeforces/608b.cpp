#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int w = 0, b= 0;
    for(int i = 0; i < s.size() ; i++){
        if(s[i] == 'W') w++;
        else b++;
    }
    if(w%2 == 1 && b%2 == 1) {
        cout << -1 << endl;
    }
    else if( b == 0 || w == 0){
        cout << 0 << endl;
    }
    else if(w%2 == 0){
        vector<int>fre;
        for(int i = 0; i < s.size() ; i++){
            if(s[i] == 'W'){
                fre.push_back(i+1);
                s[i] = 'b';
                if(s[i+1] == 'W') s[i+1] = 'B';
                else s[i+1] = 'W';
            }
        }
        cout << fre.size() << endl;
        for(int i = 0 ; i < fre.size() ; i++){
            cout << fre[i] << " ";
        }
        cout << endl;
    }
    else if(b%2 == 0){
        vector<int>fre;
        for(int i = 0; i < s.size() ; i++){
            if(s[i] == 'B'){
                fre.push_back(i+1);
                s[i] = 'W';
                if(s[i+1] == 'W') s[i+1] = 'B';
                else s[i+1] = 'W';
            }
        }
        cout << fre.size() << endl;
        for(int i = 0 ; i < fre.size() ; i++){
            cout << fre[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
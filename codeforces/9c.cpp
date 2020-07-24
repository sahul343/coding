#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t --){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        stack<int>s;
        s.push(a[0]);
        vector<int>issmaller(n, false);
        for(int i = 1; i < n; i ++){
            while(!s.empty() && s.top() > a[i]){
                s.pop();
            }
            if(!s.empty()) {
                issmaller[i] = true;
            }
            s.push(a[i]);
        }
        while(!s.empty()){
            s.pop();
        }
        s.push(a[n - 1]);
        vector<int>isbigger(n, false);
        for(int i = n - 2; i >= 0; i --){
            while(!s.empty() && s.top() < a[i]){
                s.pop();
            }
            if(!s.empty()) {
                isbigger[i] = true;
            }
            s.push(a[i]);
        }

        bool ispossible = true;
        for(int i = 0; i < n; i ++){
            if(!issmaller[i] && !isbigger[i]) {
                ispossible = false;
            }
        }
        if(ispossible){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
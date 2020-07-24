#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t --){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n ; i ++){
            cin >> a[i];
        }
        string s1 = "First", s2 = "Second";
        bool result_declared = false;
        for(int i = 0; i < n; i ++){
            if(a[i] > 1) {
                cout << s1 << "\n";
                result_declared = true;
                break;
            }
            else{
                swap(s1, s2);
            }
        }
        if(!result_declared){
            if(n%2 == 1) cout << "First"<< "\n";
            else cout << "Second" << "\n";
        }
        
    }
    return 0;
}
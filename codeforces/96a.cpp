#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t --){
        int n;
        cin >> n;
        if(n < 3) cout << "-1\n";
        else if(n%3 == 0) cout << (n/3) << " 0 0\n";
        else if(n%3 == 1 && n >= 7) {
            cout << (n - 7)/3 << " 0  1\n";
        }
        else if(n%3 == 2 && n >= 5){
            cout << (n - 5)/3 << " 1 0\n";
        }
        else{
            cout << "-1\n";
        }
    }
    return 0;
}
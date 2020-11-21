#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t --){
        int n, x;
        cin >> n >> x;
        if(n <= 2) cout << 1 << "\n";
        else{
            if((n-2)%x == 0){
                cout << (1 + (n - 2)/x) << "\n";
            }
            else{
                cout << (2 + (n - 2)/x) << "\n";
            }
        }
    }
    return 0;
}
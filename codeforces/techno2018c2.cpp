#include<bits/stdc++.h>
using namespace std;
int main(){
    int q, n;
    int ans[12] = {0, -1, -1, -1, 1, -1, 1, -1, 2, 1, 2, -1};
    cin >> q;
    while( q -- ){
        cin >> n;
        if( n  < 12){
            cout << ans[n] << "\n";
        }
        else{
            if(n%4 == 0)
                cout << n/4 << "\n";
            else if(n%4 == 1){
                cout << (n - 9)/4 + 1 << "\n";
            }
            else if(n%4 == 2){
                cout << (n - 6)/4 + 1 << "\n";
            }
            else {
                cout << (n - 15)/4 + 2 << "\n";
            }
        }
    }
    return 0;
}
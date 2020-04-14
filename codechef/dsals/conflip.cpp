#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t-- ){
        int g, n, i, q;
        cin >> g;
        while( g --){
            cin >> i >> n >> q;
            if( i == q){
                cout << n/2 << endl;
            }
            else{
                cout << (n - n/2) << endl;
            }
        }
    }
    return 0;
}
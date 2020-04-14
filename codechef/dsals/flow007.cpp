#include<iostream>
using namespace std;
int main(){
    int t, n;
    cin >> t;
    while( t-- ){
        cin >> n;
        int rever = 0;
        while(n){
            rever = rever * 10 + n %10;
            n /= 10;
        }
        cout << rever << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 31; i >= 0; i--){
        if( n & (1 << i)) cout << "1";
        else cout << "0";
    }
    cout << "\n";
    return 0;
}
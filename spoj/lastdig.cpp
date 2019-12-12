#include<bits/stdc++.h>
using namespace std;
int mypow(int a, int b){
    a %= 10;
    if( b == 0 ) return 1;
    else if( b%2 == 0 ) return mypow( (a*a)%10, b/2);
    else return (mypow((a*a)%10, b/2) * a)%10;
}
void solve(int a, int b){
    cout << mypow(a, b) << endl;
}
int main(){
    int t;
    cin >> t;
    while( t-- ){
        int a, b;
        cin >> a >> b;
        solve(a, b);
    }
    return 0;
}
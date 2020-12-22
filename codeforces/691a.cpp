#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    string red, blue;
    cin >> red >> blue;
    int r = 0, b = 0;
    for(int i = 0; i < n; i ++){
        if(red[i] > blue[i]) r ++;
        else if(red[i] < blue[i]) b ++;
    }
    if(r > b) cout << "RED\n";
    else if(r < b) cout << "BLUE\n";
    else cout << "EQUAL\n";
}
int main() {
    int t;
    cin >> t;
    while( t --){
        solve();
    }
    return 0;
}
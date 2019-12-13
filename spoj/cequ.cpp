#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b , c;
    cin >> a >> b >> c;
    if(c%__gcd(a, b) == 0) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
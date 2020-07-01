#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while ( t-- ){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        x -= a;
        x += b;
        y -= c;
        y += d;
        if( a == b && a + b > 0 && abs(x1 - x2) < 1){
            cout << "No\n";
            continue;
        }
        if(c == d && c + d > 0 && abs(y1 - y2) < 1){
            cout << "No\n";
            continue;
        }
        if( x >= x1 && x <= x2 && y >= y1 && y <= y2){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    return 0;
}
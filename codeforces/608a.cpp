#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    long ans = 0;
    if( e > f){
        int n1 = min(a, d);
        ans += n1 * e;
        a -= n1;
        d -= n1;
        ans += min(min(b, c), d) * f;
    }
    else{
        int n2 = min(min(b, c), d);
        ans += n2 * f;
        b -= n2;
        c -= n2;
        d -= n2;
        ans += min(a, d) * e;
    }
    cout << ans << endl;
    return 0;
}
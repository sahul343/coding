#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mygcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = mygcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1 *(a/b);
    return d;
}
int main(){
    ll a, b;
   while( cin >> a >> b){
        int flag = 0;
        if( a < b) { swap(a, b); flag = 1 ;}
        ll x1, y1;
        int d = mygcd(a, b, x1, y1);
        if(flag == 1) swap(x1, y1);
        cout << x1 << " " << y1 << " " << d << endl;
   }
    return 0;
}
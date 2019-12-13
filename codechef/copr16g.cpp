#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    unsigned  t,a,b;
    cin >> t;
    while( t-- ){
        cin >> a >> b;
        if(__gcd(a, b)!=1){
            cout << "-1\n";
        }
        else
        {
            cout << 1ULL*a*b-a-b+1 << "\n";
        }
        
    }
    return 0;
}
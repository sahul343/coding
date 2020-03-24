#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t-- ){
        long long a[3], n;
        cin >> a[0] >> a[1] >> a[2] >> n;
        sort(a, a+3);
        if((a[0]+a[1]+a[2]+n)%3 == 0 && (2*a[2]-a[1]-a[0])<=n){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }

        }
    
    return 0;
}
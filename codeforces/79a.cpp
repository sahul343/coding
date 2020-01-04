#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a+3);
        if((a[0]+a[1]) <= 2*a[2] && (a[0]+a[1]) >= (a[2]-1)){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    return 0;
}
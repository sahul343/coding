#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t-- ){
        long long d, n; 
        cin >> n >> d;
        if( d <= n){
            cout << "YES" << endl;
            continue;
        }
        else{
            int x = sqrt(d) - 1;
            int n1 = 0;
            if(d%(x+1) == 0){
                n1 = x + d/(x+1);
            }
            else{
                n1 = x + d/(x+1)+1;
            }
            if(n1 <= n){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }

    }
    return 0;
}
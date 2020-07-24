#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t --){
        long long a, b, n, m;
        cin >> a >> b >> n >> m;
        if( (a + b) < (n + m)){
           
            cout << "No\n";
        }
        else{
            if( (m > min(a,b)) ){
            //      cout << "here\n";
            // cout << (a + b) << " "<< (n + m);
                cout << "No\n";
            }
            else if( a > b){
                if(m <= b || ( (a-b) <= n) ){
                    cout << "Yes\n";
                }
                else{
                    cout << "No\n";
                }
            }
            else if(a < b){
                // cout << a << " " << b;
                if(m <= a || ((b-a) < n)){
                    cout << "Yes\n";
                }
                else{
                    cout << "No\n";
                }
            }
            else if( a == b){
                if(m <= a) cout << "Yes\n";
                else cout << "No\n";
            }
            // else if(min(a,b) < m && (max(a,b)-min(a,b) > n)){
            //     cout << "No\n";
            // }
            // else{
            //     cout << "Yes\n";
            // }
        }
    }
    return 0;
}
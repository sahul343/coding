#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    int a, b;
    while(t--){
        cin >> a >> b;
        long k;
        int diff = abs(a-b);
        if( a == b){
            cout << 0 << endl;
            continue;
        }
       for(int i = 0 ; i <= 100000; i++){
           k = i;
           if( ((k*(k+1))/2+a+b)%2 == 0 && (k*(k+1))/2 >= diff) {
               cout << k << endl;
               break;
           }
       }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, n;
    cin >> t;
    while( t --){
       scanf("%d",&n);
       if( n == 1){
           cout << "1\n";
           cout << "1 1\n";
       }
       else if(n%2 == 0){
           cout << n/2 << "\n";
           for(int i = 1; i <= n; i += 2){
               cout << "2 "<< i << " " << (i + 1) << "\n";
           }
       }
       else if(n%2 == 1){
           cout << n/2 << "\n";
           cout <<"3 1 2 3\n";
           for(int i = 4; i <= n; i += 2){
               cout << "2 "<< i << " " << (i + 1) << "\n";
           }
       }
    }
    return 0;
}
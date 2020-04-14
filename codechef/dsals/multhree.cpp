#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t-- ){
        long long k, d0, d1;
        cin >> k >> d0 >> d1;
        long long digit_sum = 0;
        if( k == 2){
            digit_sum = (d0 + d1);
        }
        else if(k == 3){
            digit_sum = (d0 + d1 + (d0 + d1)%10 ) ;
        }
        else{
            long long cycle_sum = ((2 *(d0 + d1))%10 + (4 *(d0 + d1))%10 +(8 *(d0 + d1))%10 + (6 *(d0 + d1))%10);
            digit_sum = (d0 + d1 + (d0 + d1)%10 + ((k - 3)/4)* cycle_sum ) ;
            k -= 3;
            if(k%4 == 1){
                digit_sum += (2 *(d0 + d1))%10;
            }
            else if(k%4 == 2){
                digit_sum += (2 *(d0 + d1))%10 + (4 *(d0 + d1))%10;
            }
            else if(k%4 == 3){
                digit_sum += (2 *(d0 + d1))%10 + (4 *(d0 + d1))%10 +(8 *(d0 + d1))%10 ;
            }
        }
       // cout << k << "\n";
        if(digit_sum%3 == 0){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
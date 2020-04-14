#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, x, k;
    cin >> t;
    while( t --){
        cin >> x >> k;
        int factors = 0;
        int cnt = 0;
        for(int i = 2; i <= sqrt(x); i++){
            while(x%i == 0){
                x /= i;
                cnt ++;
            }
        }
        if(x > 1) cnt ++;
        if(cnt >= k){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    return 0;
}
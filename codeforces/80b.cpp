#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while ( t-- ){
        int a, b;
        cin >> a >> b;
        int start = 9;
        unsigned long long ans = 0;
        while(start <= b){
            if(1+start == pow(10, int(log10(start)+1))){
                ans += a;
                start = start*10 + 9;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
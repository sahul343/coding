#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t-- ){
        int n;
        cin >> n;
        int ans = 0;
        int d = log10(n) + 1;
        ans = (d - 1) * 9;
        for(int j = 1; j <= 9; j++){
            int curr = 0;
            for(int i = 0; i < d ; i++){
                curr = curr*10 + j;
            }
            if( curr <= n) ans++;
            else break;
        }
        cout << ans << endl;
    }
    return 0;
}
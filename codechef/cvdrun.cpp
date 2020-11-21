#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t --){
        int n, k, x, y;
        cin >> n >> k >> x >> y;
        if(k == 0){
            if(x == y) cout << "YES\n";
            else cout << "NO\n";
        }
        else{
            bool flag = false;
            for(int i = 0; i < n; i ++){
                if(x == y) {
                    flag = true;
                }
                x = (x + k) % n;
            }
            if(flag) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
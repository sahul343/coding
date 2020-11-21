#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t --){
        int l, r;
        cin >> l >> r;
        if(r == 2) cout << l << " " << r << "\n";
        else if(r/2 >= l) {
            if(r%2 == 1){
                cout << r/2 << " " << (r - 1) << "\n";
            }
            else{
                cout << r/2 << " " << r << "\n";
            }
        }
        else{
            cout << -1 <<" "<< -1 << "\n";
        }
    }

    return 0;
}
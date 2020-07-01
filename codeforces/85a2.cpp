#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
int m = 1e9 + 7;
int main(){
    int t;
    cin >> t;
    while( t--){
        int n;
        cin >> n;
        int p[n + 1];
        int c[n + 1];
        bool flag = true;
        p[0] = 0, c[0] = 0;
        for(int i = 1; i <= n ; i++){
            cin >> p[i] >> c[i];
            int d1 = p[i]  - p[i - 1];
            int d2 = c[i]  - c[i - 1];
            if(d1 >= 0 && d2 >= 0 && d2 <= d1){
                continue;
            }
            else{
                flag = false;
            }
        }
        flag?cout << "YES\n":cout <<"NO\n";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int k = 1; k <= t; k++){
        int n;
        cin >> n;
        int a[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> a[i][j];
            }
        }
        int trace = 0, row = 0, col = 0;
        for(int i = 0; i < n; i++){
           trace += a[i][i];
        }
        bool rows[n + 1];
        for(int i = 0; i < n; i++){
            memset(rows, false, sizeof(rows));
            for(int j = 0; j < n; j++){
                rows[a[i][j]] = true;
            }
            for(int j = 1; j <= n; j++){
                if(rows[j] == false){
                    row ++;
                    break;
                }
            }
        }
        bool cols[n + 1];
        for(int i = 0; i < n; i++){
            memset(cols, false, sizeof(cols));
            for(int j = 0; j < n; j++){
                cols[a[j][i]] = true;
            }
            for(int j = 1; j <= n; j++){
                if(cols[j] == false){
                    col ++;
                    break;
                }
            }
        }
        printf("Case #%d: %d %d %d\n",k, trace, row, col);
    }
    return 0;
}
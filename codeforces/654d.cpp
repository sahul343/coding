#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t --){
        int n, k;
        cin >> n >> k;
        vector<vector<int> >a(n, vector<int>(n, 0));
        int diff = 0;
        while(k){
            for(int i = 0; (k > 0) && (i < n-diff); i ++, k --){
                a[i][i + diff] = 1;
                
            }
            if(diff == 0){
                diff ++;
                continue;
            }
            for(int i = diff; (i < n) && (k > 0); i ++, k --){
                a[i][i-diff] = 1;
            }
            diff ++;
        }
        int row_min = n, row_max = 0, col_min = n, col_mx = 0;
        for(int i = 0; i < n; i ++){
            int sum = 0;
            for(int j = 0; j < n; j ++){
                sum += a[i][j];
            }
            row_max = max(row_max, sum);
            row_min = min(row_min, sum);
        }
        for(int i = 0; i < n; i ++){
            int sum = 0;
            for(int j = 0; j < n; j ++){
                sum += a[j][i];
            }
            col_min = min(col_min, sum);
            col_mx = max(col_mx, sum);
        }
        cout << (col_mx - col_min) * (col_mx - col_min) + (row_max - row_min) * (row_max - row_min) << "\n";
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                cout << a[i][j];
            }
            cout << "\n";
        }
       
    }
    return 0;
}
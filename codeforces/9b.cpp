#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t --){
        int n, m;
        cin >> n >> m;
        int a[n][m];
        bool iscorrect = true;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                cin >> a[i][j];
                
                if((i == 0 && j == 0) || (i == n-1 && j == 0) || (i == n-1 && j == m-1) || (i == 0 && j == m-1) ) {
                    if(a[i][j] > 2)
                    iscorrect = false;
                }
                else if( i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(a[i][j] > 3)
                    iscorrect = false;
                }
                else if(a[i][j] > 4) iscorrect = false;
            }
        }
        if(iscorrect){
            for(int i = 0; i < n; i ++){
                for(int j = 0; j < m; j ++){
                   if((i == 0 && j == 0) || (i == n-1 && j == 0) || (i == n-1 && j == m-1) || (i == 0 && j == m-1) ) {
                       a[i][j] = 2;
                    }
                    else if( i == 0 || j == 0 || i == n-1 || j == m-1){
                        a[i][j] = 3;
                        
                    }
                    else {
                        a[i][j] = 4;
                    }
                }
            }
            cout << "YES\n";
            for(int i = 0; i < n; i ++){
                for(int j = 0; j < m; j ++){
                    cout << a[i][j] << " ";
                }
                cout << "\n";
            }
        }
        else{
            cout << "NO\n";
        }
        
    }
    return 0;
}
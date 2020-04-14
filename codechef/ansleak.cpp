#include<bits/stdc++.h>
using namespace std;
int main(){
   
    int t;
    cin >> t;
    while( t --){
        int n, m, k;
        cin >> n >> m >> k;
        int ans[n][k];
        int cnt[n][m + 1];
        memset(cnt, 0, sizeof(cnt));
        vector<bool>isdone(k+ 1, false);
        for(int i = 0; i < n; i++){
            int curr = 0;
            for(int j = 0; j < k; j++){
                cin >> ans[i][j];
               
                if(!isdone[i]){
                    cnt[i][ans[i][j]] ++;
                }
            }
            int find = 1;
            for(int j = 1; j <= m; j++){
                if(cnt[i][j] > cnt[i][find]){
                    find = j;
                }
            }
          //  cout << find << " ";
            for(int j = 0; j < n; j++){
                if(ans[i][j] == find){
                    isdone[j] = true;
                }
            }

        }
        for(int i = 0; i < n; i++){ 
          //  srand(time(0));
            cout << (rand())%m + 1<< " ";
        }
        cout << "\n";
    }
    return 0;
}
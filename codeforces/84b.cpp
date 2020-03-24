#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, t, k;
    cin >> t;
    while( t-- ){
        cin >> n;
        vector<vector<int> >a(n);
        vector<bool>isused(n,false);
        vector<bool>ismarried(n,false);

        int cnt = 0;
        int flag = 0;
        for(int i = 0; i < n; i++){
            int x;
            cin >> k;
            for(int j = 0; j < k; j++){
                cin >> x;
                x--;
                a[i].push_back(x);
            }
            sort(a[i].begin(), a[i].end());
            for(int j = 0; j < k ; j++){
                if(!isused[a[i][j]]) {
                    isused[a[i][j]] = true;
                    ismarried[i] = true;
                    cnt ++;
                  //  cout << a[i][j] << " ";
                    break;
                }
            }
        }
        if(cnt == n){
            cout << "OPTIMAL\n";
        }
        else{
            for(int i = 0; i < n; i++){
                if(!ismarried[i]){
                    for(int j = 0; j < n; j++){
                        if(!isused[j]){
                            cout << "IMPROVE\n";
                            cout << (i+1) << " " << (j+1) << "\n";
                            break;
                        }
                    }
                    i = n;
                }
            }
        }

    }
    return 0;
}
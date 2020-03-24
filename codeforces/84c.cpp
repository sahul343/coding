#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>>start(k);
    vector<pair<int,int>>end(k);
    for(int i = 0; i < k; i++){
        cin >> start[i].first >> start[i].second;
    }
    for(int i = 0; i < k; i++){
        cin >> end[i].first >> end[i].second;
    }
    cout << 2*n*m -2 << endl;

    for(int i = 0; i <n; i++){
        if(i%2 == 0){
            for(int j = 0; j < m-1; j++){
                cout << "R";
            }
        }
        else{
            for(int j = 0; j < m-1; j++){
                cout << "L";
            }
        }
        if( i < n-1) cout << "D";
    }
     for(int i = 0; i <n; i++){
        if(i%2 == 0){
            for(int j = 0; j < m-1; j++){
                cout << "L";
            }
        }
        else{
            for(int j = 0; j < m-1; j++){
                cout << "R";
            }
        }
        if( i < n-1) cout << "U";
    }
    cout << endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, n;
    cin >> t;
    while( t --){
        cin >> n;
        int x;
        vector<int>pos;
        for(int i = 0; i < n; i++){
            cin >> x;
            if( x == 1) pos.push_back(i);
        }
        bool flag = true;
        for(int i = 1; i < pos.size(); i++){
            if(pos[i] - pos[i - 1] < 6){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
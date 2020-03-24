#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t-- ){
        int n;
        cin >> n;
        vector<pair<int,int>>pos(n);
        for(int i = 0; i < n; i++){
            cin >> pos[i].first >>pos[i].second;
        }
        bool flag = false;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if((pos[i].first - pos[j].first)*(pos[i].second-pos[j].second) < 0){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag){
            cout << "NO\n";
        }
        else{
            int x = 0, y = 0;
            string ans ;
            sort(pos.begin(), pos.end());
            for(int i = 0; i < n; i++){
                while(x < pos[i].first){
                    x++;
                    ans.push_back('R');
                }
                while(y < pos[i].second){
                    y++;
                    ans.push_back('U');
                }
            }
            ans.push_back('\n');
            cout << "YES\n";
            cout << ans ;
        }
    }
    return 0;
}
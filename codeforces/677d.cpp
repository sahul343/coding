#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>a){
    int n = a.size();
    map<int,vector<int> >m;
    for(int i = 0; i < n; i ++){
        m[a[i]].push_back((i + 1));
    }
    if(m.size() == 1){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        vector<vector<int> >groups;
        for(auto it: m){
            groups.push_back(it.second);
        }
        int m = groups.size();
        for(int i = 1; i < m; i ++){
            cout << groups[i - 1][0] << " " << groups[i][0] << "\n";
        }
        for(int i = 0; i < m; i ++){
            int size = groups[i].size();
            for(int j = 1; j < size; j ++){
                cout << groups[(i + 1)%m][0] << " " << groups[i][j] << "\n";
            }
        }
    }
}
int main(){
    int t;
    cin >> t;
    while( t --){
        int n;
        cin >> n;
        vector<int>a(n);
        for(int i = 0; i < n; i ++){
            cin >> a[i];
        }
        solve(a);
    }
    return 0;
}
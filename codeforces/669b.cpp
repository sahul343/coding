#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t -- ){
        int n;
        cin >> n;
        vector<int>ans;
        vector<int>a(n);
        for(int i = 0; i < n; i ++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i += 2){
            if(a[i] == a[i +1]){
                ans.push_back(a[i]);
                ans.push_back(a[i + 1]);
            }
            else{
                ans.push_back(0);
            }
        }
        int k = ans.size();
        cout << k << "\n";
        for(auto val: ans){
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}
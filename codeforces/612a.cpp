#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t-- ){
        int k;
        cin >> k;
        string s;
        cin >> s;
        s.push_back('A');
        k++;
        int ans = 0;
        vector<int>angry;
        for(int i = 0; i < k; i++){
            if(s[i] == 'A'){
                angry.push_back(i);
            }
        }
        for(int i = 0; i < angry.size()-1; i++){
            ans = max(ans, angry[i+1] - angry[i] - 1);
        }
        cout << ans << endl;
    }
    return 0;
}
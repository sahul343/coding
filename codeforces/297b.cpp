#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    int m, idx;
    cin >> m;
    vector<int>diff(n + 1, 0);
    for(int i = 0; i < m; i ++){
        cin >> idx;
        diff[idx - 1] += 1;
        //diff[idx] -= 1;
    }
    int sum = 0;
    for(int i = 0; i < n/2; i ++){
        sum += diff[i];
        if(sum%2 == 1){
            swap(s[i], s[n - i - 1]);
        }
    }
    cout << s << "\n";
    return 0;
}
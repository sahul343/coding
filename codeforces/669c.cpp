#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    vector<int>curr;
    for(int i = 0; i < n; i ++){
        curr.push_back(i);
    }
    vector<bool>isfound(n, false);
    vector<int>ans(n);
    int cnt = 0;
    int val1, val2;
    while(cnt < n){
        vector<int>next;
        for(int i = 1; i < curr.size(); i += 2){
            cout << "? " << (curr[i - 1] + 1) << " " << (curr[i] + 1) << endl;
            //cout.flush();
            cin >> val1;
            cout << "? " << (curr[i] + 1) << " " << (curr[i - 1] + 1) << endl;
            //cout.flush();
            cin >> val2;
            if(val1 > val2){
                cnt ++;
                isfound[curr[i - 1]] = true;
                ans[curr[i - 1]] = val1;
                next.push_back(curr[i]);
            }
            else{
                cnt ++;
                isfound[curr[i]] = true;
                ans[curr[i]] = val2;
                next.push_back(curr[i - 1]);
            }
        }
        if( (curr.size())%2 == 1){
            next.push_back(curr.back());
        }
        curr = next;
        if(curr.size() == 1){
            ans[curr[0]] = n;
            break;
        }
    }
    cout << "! ";
    for(auto val: ans){
        cout << val << " ";
    }
    cout << endl;
    //cout.flush();
    return 0;
}
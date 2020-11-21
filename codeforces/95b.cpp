#include<bits/stdc++.h>
using namespace std;
bool ispossible(int* a, vector<int>&b, vector<bool>&islocked){
    int n = islocked.size();
    sort(b.begin(), b.end(),greater<int>());
    int idx = 0;
    for(int i = 0; i < n; i ++){
        if(!islocked[i]){
            a[i] = b[idx ++];
        }
    }
    bool flag = true;
    int sum = 0;
    for(int i = 0; i < n; i ++){
        sum += a[i];
        if(sum < 0){
            flag = false;
        }
    }
    return flag;
}
int main(){
    int t;
    cin >> t;
    while( t --){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i ++){
            cin >> a[i];
        }
        vector<bool>islocked(n, false);
        int x;
        vector<int>b;
        //int negsum = 0, possum = 0;
        for(int i = 0; i < n; i ++){
            cin >> x;
            if(x == 0) {
                islocked[i] = false;
                b.push_back(a[i]);
            }
            else islocked[i] = true;
        }
        if(ispossible(a, b, islocked)){
            for(int i = 0; i < n; i ++){
                cout << a[i] << " ";
            }
            cout << "\n";
            continue;
        }
        sort(b.begin(), b.end());
        int pos = 0;
        if(b.size() != 0){
            for(int i = 0; i < (b.size()); i ++){
                if(b[i] > 0){
                    pos = i;
                    break;
                }
            }
            sort(b.begin() + pos, b.end(), greater<int>());
        }
        int idx1 = 0, idx2 = pos;
        int sum = 0;
        int possum = 0, negsum = 0;
        for(int i = 0; i < n; i++){
            if(a[i] < 0) negsum += a[i];
            else possum += a[i];
        }
        for(int i = 0; i < n; i ++){
            if(!islocked[i]) {
                if(idx2 == (b.size()) || (idx1 < pos && (possum + sum - negsum) < 0) ){
                    a[i] = b[idx1];
                    negsum -= a[i];
                    idx1 ++;
                }
                else {
                    a[i] = b[idx2];
                    possum -= a[i];
                    idx2 ++;
                }
            }
            sum += a[i];
        }
        for(int i = 0; i < n; i ++){
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
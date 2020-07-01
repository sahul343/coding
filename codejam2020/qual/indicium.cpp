#include<bits/stdc++.h>
using namespace std;
bool isthis(int *a, int k, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += (a[i] + i)%n;
    }
    // cout << k << endl;
    // cout << sum << endl;
    return sum == k;
}
//void makenext(vector<int>&a){
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        int n, k;
        cin >> n >> k;
        int p[n];
        for(int j = 0; j < n; j++){
            p[j] = j;
        }
        k -= n;
        bool flag = false;
        if(isthis(p, k, n)){
            flag = true;
        }
        while(!flag && next_permutation(p, p + n) ){
            if(isthis(p, k, n)){
                flag = true;
                break;
            }

        } 
        if(!flag){
            printf("Case #%d: IMPOSSIBLE\n",i);
        }
        else{
            printf("Case #%d: POSSIBLE\n",i);
            for(int i = 0; i < n; i++){
                int curr = p[i];
                for(int j = 0; j < n; j++){
                    cout << (curr + j)%n + 1 << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; 
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int x = 0;
    int till_now = a[n-1];
    int p = pow(2, 29);
    for(int i = 30; i >= 0; i--){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(a[j]&p) count ++;
        }
        if(count > 0)

        p /= 2;
    }
    return 0;
}
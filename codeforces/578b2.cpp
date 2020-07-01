#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while ( t-- ){
        int n, m, k;
        cin >> n >> m >> k;
        int h[n];
        for(int i = 0; i < n; i++){
            cin >> h[i];
        }
        int curr = 0;
        while(curr < n - 1 ){
            m += h[curr] - max(0, h[curr+1] - k);
            if(m < 0) break;
            curr ++;
        }
        if(curr == n-1){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
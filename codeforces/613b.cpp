#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t-- ){
        int n;
        cin >> n;
        vector<int>a(n);
        bool flag = true;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
        long long mx = INT_MIN;
        long long sum1 = 0;
        for(int i = 0; i < n-1; i++){
            sum1 += a[i];
            mx = max(mx, sum1);
            if(sum1 < 0){
                sum1 = 0;
            }
        }
        sum1 = 0;
         for(int i = 1; i < n; i++){
            sum1 += a[i];
            mx = max(mx, sum1);
            if(sum1 < 0){
                sum1 = 0;
            }
        }
        if(sum > mx){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        // cout << mx << endl;
        // cout << sum << endl;

    }
    return 0;
}
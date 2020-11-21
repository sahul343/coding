#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t --){
        int n, m;
        cin >> n >> m;
        long long sum = 0;
        int a[n];
        for(int i = 0; i < n; i ++){
            cin >> a[i];
            sum += a[i];
        }
        if(sum != m){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t-- ){
        int n, s;
        cin >> n >> s;
        int a[n];
        unsigned long long sum = 0;
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
            sum += a[i];
        }
        if(sum <= s){
            cout <<"0\n";
            continue;
        }
        sum = 0;
        int mx = 0;
        int k = 0;
        while(k<n && (sum+a[k] <= s)){
            sum += a[k];
            k++;
            if(a[k] > a[mx]){
                mx = k;
            }
        }
        int answer = k;
        int cnt = 0;
        sum -= a[mx];
        while(k < n){
            if(sum + a[k] > s)break;
            sum += a[k];
            k++;
            cnt++;
        }
        if(cnt > 1){
            cout << mx+1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    return 0;
}
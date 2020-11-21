#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    set<long long>s;
    s.insert(0);
    long long sum = 0;
    long long ans = 0;
    for(int i  = 0; i < n; i ++){
       sum += a[i];
       if(s.find(sum) != s.end()){
           ans ++;
           s.clear();
           s.insert(0);
           sum = a[i];
       }
       s.insert(sum);
    }
    cout << ans << "\n";
    return 0;
}
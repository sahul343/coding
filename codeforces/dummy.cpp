#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >>n;
    vector<int>a(n);
    for(int i =0; i < n; i++){
        cin >> a[i];
    }
    int x;
    cin >> x;
    sort(a.begin(), a.end());
    int ans = upper_bound(a.begin(), a.end(), x)-a.begin();
    cout << ans << endl;
}
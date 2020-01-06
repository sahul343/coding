#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<string>a(n);
    vector<string>b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int year;
        cin >> year;
        year --;
        string ans = a[year%n]+b[year%m];
        cout << ans << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
unsigned long long mygcd(unsigned long long a, unsigned long long b){
    if( a < b) swap(a, b);
    while(b){
        unsigned long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<unsigned long long>a(n), b(m);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i ++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    unsigned long long g = 0;
    for(int i = 1; i < n; i ++){
        g = mygcd(g, a[i] - a[i - 1]);
    }
    for(int i = 0; i < m; i ++){
        unsigned long long rowGcd = mygcd(g, a[0] + b[i]);
        cout << rowGcd << " ";
    }
    cout << "\n";
    return 0;
}
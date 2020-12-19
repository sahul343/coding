#include<bits/stdc++.h>
using namespace std;
void quickSortVariant(vector<int>a, set<long long>&s){
    vector<int>left;
    vector<int>right;
    int mn = a[0], mx = a[0], n = a.size();
    if(n <= 0) return;
    long long sum = 0;
    for(int i = 0; i < n; i ++){
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
        sum += a[i];
    }
    s.insert(sum);
    // cout << "inserting sum: " << sum << " and size " << n << "\n";
    if(n == 1) return;
    int mid = (mn + mx)/2;
    if(mid == mx) return;
    for(int i = 0; i < n; i ++){
        if(a[i] <= mid) left.push_back(a[i]);
        else right.push_back(a[i]);
    }
    if((left.size()) > 0)
    quickSortVariant(left, s);
    if((right.size()) > 0)
    quickSortVariant(right, s);
    return;
}
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int>a(n);
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    vector<int>s(q);
    for(int i = 0; i < q; i ++){
        cin >> s[i];
    }
    set<long long>pretty;
    quickSortVariant(a, pretty);
    for(int i = 0; i < q; i ++){
        if(pretty.find(s[i]) != pretty.end()){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
}
int main(){
    int t;
    cin >> t;
    while( t --){
        solve();
    }
    return 0;
}
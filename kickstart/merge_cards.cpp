#include<bits/stdc++.h>
using namespace std;
void recurse(vector<long int>a, vector<double>& val, double ans, unsigned long long &cnt){
    if(a.size() <= 0) return;
    else if(a.size() == 1){
        val.push_back(ans);
        cnt ++;
        return;
    }
    else{
        int n = a.size();
        for(int i = 0; i < (n - 1); i ++){
            vector<long int>curr;
            for(int j = 0; j < i; j ++){
                curr.push_back(a[j]);
            }
            curr.push_back(a[i] + a[i + 1]);
            ans += a[i] + a[i + 1];
            for(int j = i + 2; j < n; j ++){
                curr.push_back(a[j]);
            }
            recurse(curr, val, ans, cnt);
            ans -= (a[i] + a[i + 1]);
        }
    }
}
double solve (){
    int n;
    cin >> n;
    vector<long int>a(n);
    double ans = 0;
    unsigned long long cnt = 0;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    vector<double>vals;
    recurse(a, vals, ans, cnt);
    for(double val: vals){
        ans += val;
    }
    ans = ans/cnt;
    return ans;
}
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i ++){
        double ans = solve();
        cout << "Case #" << i << ": ";
        cout << fixed << setprecision(6) << ans << "\n";
    }
    return 0;
}
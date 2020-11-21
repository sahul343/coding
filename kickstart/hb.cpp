#include<bits/stdc++.h>
using namespace std;
unsigned long long mypow(int a, int n){
    if(n == 0) return 1;
    unsigned long long ans = 1;
    for(int i = 1; i <= n; i ++){
        ans = ans * a;
    }
    return ans;
}
unsigned long long boringCnt(unsigned long long l){
    if(l == 0) return 0;
    string s = to_string(l);
    unsigned long long ans = 0;
    int n = s.size();
    for(int i = 0; i < n; i ++){
        unsigned long long x = (s[i] - '0' + 1);
        //cout << "x: " << x << "\n";
        //cout  << (x/2) << ", " << (mypow(5, n - i - 1)) << "\n";
        if(i == n - 1 && (i%2 == 1)){
            if((s[i] - '0')%2 == 0 && (i != 0)) x += 1;
        }
        ans += (x/2)* (mypow(5, n - i - 1));
        if(i%2 == (s[i] - '0')%2) break;
    }
    bool isEven = false;
    unsigned long long extra = 0;
    for(int i = 0; i <= (n - 2); i ++){
        unsigned long long len = (n - i - 1);
        unsigned long long threshold = 2 * mypow(10, len);
        if(l >= threshold && (((s[i] - '0')%2 == 0) || isEven)){
            isEven = true;
            //cout << (mypow(5, len)) << "\n";
            extra += (mypow(5, len ));
        }
        isEven = true;
    }
    ans += extra;
    return ans;
}
unsigned long long solve(){
    unsigned long long l, r;
    cin >> l >> r;
    unsigned long long cnt1 = boringCnt(l - 1);
    unsigned long long cnt2 = boringCnt(r);
    return (cnt2 - cnt1);
}
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i ++){
        cout << "Case #"<<i << ": " << (solve()) << "\n";
    }
    return 0;
}
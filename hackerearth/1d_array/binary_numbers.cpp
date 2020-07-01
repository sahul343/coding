#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fib[40];
ll cum[40];
string solve(int k){
    if(k == 0) return "0";
    else if(k == 1) return "1";
    else if(k == 2) return "10";
    auto itr = upper_bound(cum, cum + 40, k) - cum;
    if(cum[itr - 1] == k){
        itr --;
    }
   // cout << itr << endl;
    string ans = "10";
    string rest = solve(k - 1 - cum[itr - 1]);
    int size_rest = rest.size();
    for(int i = 2; i < itr - size_rest; i ++){
        ans.push_back('0');
    }
    ans += rest;
    return ans;
}
int main(){
    int t;
    fib[1] = 1;
    fib[2] = 1;
    cum[1] = 1;
    cum[2] = 2;
    for(int i = 3; i <= 40; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
        cum[i] = fib[i] + cum[i - 1];
    }
    cin >> t;
    while(t --){
        int k;
        cin >> k;
        cout << solve(k) << endl;
    }
    return 0;
}
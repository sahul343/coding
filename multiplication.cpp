#include<bits/stdc++.h>
using namespace std;
string multiply(string s, int n){
    int carry = 0;
    string result;
    int sz = s.size();
    for(int i = sz - 1; i >= 0; i --){
        int sum = n * (s[i] - '0') + carry;  // '0', '1', ...., '9'  '4' - '0' = 4
        result.push_back( '0' + (sum%10));
        carry = sum/10;
        //sum = sum/10 * 10 + sum%10, 12 = 1 * 10 + 2
    }
    while(carry > 0){
        result.push_back('0' + carry%10); // '0' + 4 = '4'
        carry = carry / 10;
    }
    reverse(result.begin(), result.end()); //"abc" => "cba"
    return result;
}
string factorial(int n){
    string ans = "1";
    for(int i = 2; i <= n; i ++){
        ans = multiply(ans, i);
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    cout << factorial(n) << "\n";
    return 0;
}
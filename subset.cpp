#include<bits/stdc++.h>
using namespace std;
int no_bits(int x){
    int cnt = 0;
    while(x){
        cnt ++;
        x /= 2;
    }
    return cnt;
}
int sum_cnt(int a, int b){
    int sum = 0; 
    for(int i = 0; i < b; i ++){
        if(a%2 == 0) sum --;
        else sum ++;
        a /= 2;
    }
    return sum;
}
void calculate(int* a, int idx, int n, int &ans, int sum){
    if(idx == n) return;
    for(int i = idx; i < n; i ++){
        sum += a[i];
        if(sum == 0) ans ++;
        calculate(a, i + 1, n, ans, sum);
        sum -= a[i];
    }
}
string final_ans(int ans, int b){
    string s;
    for(int i = 0; i < b; i ++){
        if(ans % 2 == 0) s.push_back('0');
        else s.push_back('1');
        ans /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    int mx = 0;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int b = no_bits(mx);
    for(int i = 0; i < n; i ++){
        a[i] = sum_cnt(a[i], b);
    }
    int ans = 0, sum = 0;
    calculate(a, 0, n, ans, sum);

    cout << final_ans(ans, b) << "\n";
    return 0;
}
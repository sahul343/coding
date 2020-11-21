#include<bits/stdc++.h>
using namespace std;
long long BinConcat(int x, int y){
    string s1, s2;
    int a = x;
    while(a){
        s1.push_back(a%2 + '0');
        a /= 2;
    }
    a = y;
    while(a){
        s2.push_back(a%2 + '0');
        a /= 2;
    }
    reverse(s1.begin(), s2.end());
    reverse(s2.begin(), s2.end());
    string xy = s1 + s2, yx = s2 + s1;
    long long ans = 0;
    for(int i = 0; i < xy.size(); i ++){
        if(xy[i] == yx[i]){
            continue;
        }
        else if(xy[i] == '1'){
            ans = ans * 2 + 1;
        }
        else{
            ans = ans * 2 - 1;
        }
    }
    return abs(ans);
}
int main(){
    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i ++){
            cin >> a[i];
        }
        long long ans = 0;
        for(int i = 0; i < n; i ++){
            for(int j = i + 1; j < n; j ++){
                ans = max(ans, BinConcat(a[i], a[j]));
            }
        }
    }
    return 0;
}
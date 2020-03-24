#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, n;
    string s;
    cin >> t;
    while(t--){
       cin >> n >> s;
       vector<bool>isused(n, false);
       int i = 0, j = n-1;
       bool flag = true;
       int cnt = 0;
       while(i<j){
           if(s[i] != s[j]){
                if(j-i >=2 && (s[i] == s[j-1]) && !isused[j] && !isused[j-1]){
                    swap(s[j],s[j-1]);
                    cnt ++;
                    isused[j] = true;
                    isused[j - 1] = true;
                }
                else if(j-i >=2 && (s[j] == s[i+1]) && !isused[i] && !isused[i+1]){
                    swap(s[i],s[i+1]);
                    cnt ++;
                    isused[i] = true;
                    isused[i+1] = true;
                }
                else{
                    flag = false;
                    break;
                }
           }
           i++, j--;
       }
       if(flag){
           cout << "YES\n";
           cout << cnt << endl;
       } 
       else{
           cout << "NO\n";
       }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  string s;
  while( t -- ){
    cin >> s;
    string ans;
    int n = s.size();
    if(n >= 1){
      ans.push_back(s[0]);
    }
    for(int i = 1; i < n - 1; i += 2){
      ans.push_back(s[i]);
    }
    if(n > 1){
      ans.push_back(s[n-1]);
    }
    cout << ans << "\n";
  }
  return 0;
}

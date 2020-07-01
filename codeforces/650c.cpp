#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  while( t --){
      int n, k;
      cin >> n >> k;
      string s;
      cin >> s;
      vector<int>ones;
      for(int i = 0; i < n; i ++){
          if(s[i] == '1'){
              ones.push_back(i);
          }
      }
      int ans = 0;
      if(ones.size() == 0){
          ans = 1 + (n - 1)/(k + 1);
          cout << ans << "\n";
          continue;
      }
      else{
            int onesize = ones.size();
            for(int i = 0; i < onesize - 1; i ++){
                int length = ones[i + 1] - ones[i] - 1;
                if(length -  k > 0){
                    ans += (length - k)/(k + 1);
                }
            }
            int length_start = ones[0];
            if(length_start  > 0){
                ans += (length_start)/(k + 1);
            }
            int length_end = n - (1 + ones[onesize - 1]);
            if(length_end > 0){
                ans += (length_end)/(k + 1);
            }
            cout << ans << "\n";
      }
  }
  return 0;
}

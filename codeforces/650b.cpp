#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  while( t --){
      int n; 
      cin >> n;
      int a[n];
      int odd = 0, even = 0;
      for(int i = 0; i < n; i++){
          cin >> a[i];
          if(i%2 == 0 && a[i]%2 == 1){
              even ++;
          }
          if(i%2 == 1 && a[i]%2 == 0){
              odd ++;
          }
      }
      if(even == odd){
          cout << even << "\n";
      }
      else{
          cout << "-1\n";
      }
  }
  return 0;
}

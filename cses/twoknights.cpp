#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  if(n == 1){
    cout << "0\n";
  }
  else if(n == 2){
    cout << "0\n6\n";
  }
  else if(n == 3){
    cout << "0\n6\n28\n";
  }
  else if(n == 4){
    cout << "0\n6\n28\n96\n";
  }
  else{
    long long a[n + 1];
    a[1] = 0;
    a[2] = 6;
    a[3] = 28;
    a[4] = 96;
    for(long long i = 5; i <= n; i ++){
      a[i] = a[i - 1];
      a[i] += 2 * i * i * i - 3*i * i - 7 * i + 16;
      // a[i] -= (i - 1) * ( 2 * i - 1);
    }
    for(int i = 1; i <= n; i ++){
      cout << a[i] << "\n";
    }
  }
  return 0;
}

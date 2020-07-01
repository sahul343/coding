#include<bits/stdc++.h>
using namespace std;
struct point{
  int x, y;
  bool operator<(const point &p){
    if(x == p.x) return y < p.y;
    else return x < p.x;
  }
};
int main(){
  int n ;
  cin >> n;
  vector<point> p(n);
  for(int i = 0; i < n; i++){
    cin >> p[i].x >> p[i].y;
  }
  sort(p.begin(), p.end());
  for(int i = 0; i < n; i++){
    cout << p[i].x << " " << p[i].y << "\n";
  }
  return 0;
}

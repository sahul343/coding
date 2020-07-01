#include<bits/stdc++.h>
using namespace std;
struct point {
    int x, y;
    bool operator<(const point &p){
        if(x == p.x)return y < p.y;
        else return x < p.x;
    }
};
int main(){
    int n;
    cin >> n;
    point a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y;
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        cout << a[i].x << " " << a[i].y << "\n";
    }
    cout << "\n";
    return 0;
}
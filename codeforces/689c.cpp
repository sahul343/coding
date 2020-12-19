#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair;
#define REP(i, a, b) for(int i = a; i <= b; i++)
int m = 1e9 + 7;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int>a(n);
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    vector<pair<int, double> >events(m);
    for(int i = 0; i < m; i ++){
        cin >> events[i].first >> events[i].second;
    }
    
    int x =  n - 1;
    for(int i = n - 1; i >= 0; i --){
        if(a[i] != (i + 1)){
            x = i;
            break;
        }
        x -= 1;
    }
    if(x == -1){
        cout << 1 << "\n";
    }
    else{
        x ++;
        double ans = 1;
        for(int i = 0; i < m; i ++){
            if(events[i].first >= x){
                ans *= (1.0 - events[i].second);
            }
        }
        ans = 1.0 - ans;
        cout << fixed << setprecision(9) << ans << "\n";
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while( t --){
        solve();
    }
    return 0;
}
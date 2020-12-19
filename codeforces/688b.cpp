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
int solve(){
    int n;
    cin >> n;
    long long a[n];
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    long long ans = 0;
    for(int i = 0; i < n - 1; i ++){
        ans += abs(a[i] - a[i + 1]);
    }
    long long diff = abs(a[1] - a[0]);
    if(n > 2){
        diff = max(diff, abs(a[n - 1] - a[n - 2]));
    }
    for(int i = 1; i < n - 1; i ++){
        diff = max(diff, abs(a[i] - a[i + 1]) + abs(a[i] - a[i - 1])  - abs(a[i + 1] - a[i - 1]));
    }
    // cout << ans << " " << diff << "\n";
    ans -= diff;
    cout << ans << "\n";
}
int main(){
    int t;
    cin >> t;
    while( t --){
        solve();
    }
    return 0;
}
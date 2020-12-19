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
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> cnt(100, 0);
    int x;
    for(int i = 0; i < n; i ++){
        cin >> x;
        cnt[x - 1] = (cnt[x - 1] + 1);
    }
    for(int i = 0; i < m; i ++){
        cin >> x;
        cnt[x - 1] = (cnt[x - 1] + 1);
    }
    int sum = 0;
    for(int i = 0; i < 100; i ++){
        if(cnt[i] > 0)
        sum ++;
    }
    cout << (m + n - sum) << "\n";
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
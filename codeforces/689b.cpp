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
    vector<string>grid(n);
    for(int i = 0; i < n; i ++){
        cin >> grid[i];
    }
    int dp[n][m];
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            if(j == 0){
                dp[i][j] = (grid[i][j] == '*' ? 1 : 0);
            }
            else{
                dp[i][j] = dp[i][j - 1] + (grid[i][j] == '*' ? 1 : 0);
            }
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            if(grid[i][j] == '*'){
                int row = i, left = j, right = j;
                while(left >= 0 && right < m && row < n){
                    int cnt = (right - left) + 1;
                    int actual = dp[row][right];
                    if(left != 0) actual -= dp[row][left - 1];
                    if(actual == cnt){
                        ans ++;
                    }
                    else{
                        break;
                    }
                    row ++;
                    right ++;
                    left --;
                }
            }
        }
    }
    cout << ans << "\n";
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
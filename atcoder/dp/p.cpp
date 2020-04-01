#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long dp[N];
vector<int>a[N];
vector<bool>isvisited(N, false);
const int m = 1e9 + 7;
long long solve(int u,int p){
    if(dp[u] != -1)return dp[u];
    long long ans1 = 1,ans2 = 1;
    for(auto v: a[u]){
        if(v == p) continue;
        ans1 = (ans1 * solve(v, u)) % m;
        for(auto w : a[v]){
            if(w == u) continue;
            ans2 = (ans2 * solve(w,v)) % m;
        }
    }
    dp[u] = (ans1 + ans2)%m;
    return dp[u];
}
int main(){
    int n, x, y;
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> x >> y;
        x --, y --;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    memset(dp, -1, sizeof(dp));  
    solve(0, -1);
    cout << dp[0] << endl;
}
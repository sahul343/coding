#include<bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int> >&g, vector<bool>&visited, vector<int>&dp, int u){
    if(visited[u]) return dp[u];
    visited[u] = true;
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        dp[u] = max(dp[u], 1 + dfs(g, visited, dp, v ));
    }
    return dp[u];
}
int main(){
    int n, m, x, y;
    cin >> n >> m;
    vector<vector<int> >g(n);
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        x --, y --;
        g[x].push_back(y);
    }
    vector<bool>isvisited(n, false);
    vector<int>dp(n, 0);
    for(int i = 0; i < n; i++){
        if(!isvisited[i]){
            dfs(g, isvisited, dp, i);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(dp[i], ans);
    }
    cout << ans << endl;
    return 0;
}
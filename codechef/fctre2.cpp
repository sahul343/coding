#include<bits/stdc++.h>
using namespace std;
#define ll int
ll n;
int dp[1005][1005];
ll inv[20005];
const ll mod = 1e9 + 7;
int sum_together(unordered_map<int,int>&source, unordered_map<int,int>&dest, int ans1){
    for(auto x : source){
        if(dest.find(x.first) != dest.end()){
            ans1 = (ans1 *1ll *inv[dest[x.first] + 1])%mod;
            ans1 = (ans1 + mod)%mod;
            dest[x.first] = (dest[x.first] + x.second)%mod;
        }
        else{
            dest[x.first] = x.second;
        }
        ans1 = (ans1 *1ll* (dest[x.first] + 1))%mod;
        ans1 = (ans1 + mod)%mod;
    }
    return ans1;
}
void make_it_back(unordered_map<int,int>&source, unordered_map<int,int>&dest){
    for(auto x : source){
        dest[x.first] -= x.second;
        if(dest[x.first] == 0){
            dest.erase(x.first);
        }
    }
}
void dfs(int u, int root, vector<vector<int> > &adj, unordered_map<int,int> *m, unordered_map<int,int>mroot, vector<bool>&visited){
    visited[u] = true;
    for(ll v : adj[u]){
        if(!visited[v]){
            dp[root][v] = sum_together(m[v], mroot, dp[root][u]);
            dfs(v,root, adj, m, mroot, visited);
            make_it_back(m[v], mroot);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    inv[1] = 1;
    for(int i = 2; i <= 20000; ++i)
        inv[i] = (mod- (mod/i) *1ll* inv[mod%i] % mod) % mod;
    int t;
    cin >> t;
    while( t --){
        int x, y;
        cin >> n;
        vector<vector<int> > adj(n);
        int cost[n];
        unordered_map<int,int>m[n];
        unordered_map<int,int>mroot[n];
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n - 1; i++){
            cin >> x >> y;
            x--, y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(int i = 0; i < n; i++){
            cin >> cost[i];
        }
        for(int i = 0; i < n; i++){
            int no_factors = 1;
            int curr = cost[i];
            for(int j = 2; j <= sqrt(curr); j++){
                int cnt = 0;
                while(curr%j == 0){
                    curr /= j;
                    cnt ++;
                }
                if(cnt > 0){
                    m[i][j] = cnt;
                    mroot[i][j] = cnt;
                    no_factors = (no_factors *1ll* (cnt + 1))%mod;
                }
            }
            if(curr > 1){
                m[i][curr] = 1;
                mroot[i][curr] = 1;
                no_factors = (no_factors *1ll*  2)%mod;
            }
            dp[i][i] = no_factors;
        }
        vector<bool>isvisited(n, false);
        for(int i = 0; i < n; i++){
            dfs(i, i, adj, m, mroot[i], isvisited);
            isvisited.assign(n, false);
        }
        int queries;
        cin >> queries;
        for(int i = 0; i < queries; i++){
            cin >> x >> y;
            x --, y --;
            cout << dp[x][y] << "\n";
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll int
ll n, level;
int timer = 0;
vector<int> tin, tout;
vector<vector<int> > up;
const ll mod = 1e9 + 7;
void sum_together(unordered_map<int,ll>&source, unordered_map<int,ll>&dest){
    for(auto x : source){
        if(dest.find(x.first) != dest.end()){
            dest[x.first] = (dest[x.first] + x.second)%mod;
        }
        else{
            dest[x.first] = x.second;
        }
    }
}
ll get_ans(unordered_map<int,ll> m){
    ll ans = 1;
    for(auto x: m){
        ans = (ans *1ll* (x.second + 1))%mod;
    }
    return ans;
}
void factor_two_number(unordered_map<int,ll>&m1, unordered_map<int,ll>&m2, int a,  unordered_map<int,ll> &res){
    for(auto x: m1){
        res[x.first] = (a *1ll* x.second)%mod;
    }
    for(auto x: m2){
        if(res.find(x.first) == res.end()){
            res[x.first] =  m2[x.first];
        }
        else{
            res[x.first] += m2[x.first];
        }
    }
   // return res;
}
// void dfs(int u, vector<vector<int> > &adj, unordered_map<int,ll> *m, unordered_map<int,ll> *mroot, vector<bool>&visited){
//     if(u == 0){
//         mroot[u] = m[u];
//     }
//     visited[u] = true;
//     for(ll v : adj[u]){
//         if(!visited[v]){
//            // parent[v] = u;
//             mroot[v] = m[v];
//             sum_together(mroot[u], mroot[v]);
//             dfs(v, adj, m, mroot, visited);
//         }
//     }
    
// }
bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
void solve(int v, int p, vector<vector<int> >&adj, unordered_map<int,ll> *m, unordered_map<int,ll> *mroot){
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= level; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    if(v == 0){
        mroot[0] = m[0];
    }
    for (int u : adj[v]) {
        if (u != p){
            mroot[u] = m[u];
            sum_together(mroot[v], mroot[u]);
            solve(u, v, adj, m, mroot);
        }
    }
    tout[v] = ++timer;
}
int lca(int u, int v){
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = level; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while( t --){
        int x, y;
        cin >> n;
        level = ceil(log2(n));
        tin.resize(n);
        tout.resize(n);
        timer = 0;
        up.assign(n, vector<int>(level + 1));
        vector<vector<int> > adj(n);
        int cost[n];
        unordered_map<ll, int>answers;
        unordered_map<int,ll>m[n];
        for(int i = 0; i < n - 1; i++){
            cin >> x >> y;
            x--, y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(int i = 0; i < n; i++){
            int no_factors = 1;
            cin >> cost[i];
            int curr = cost[i];
            for(int j = 2; j <= sqrt(curr); j++){
                int cnt = 0;
                while(curr%j == 0){
                    curr /= j;
                    cnt ++;
                }
                m[i][j] = cnt;
                no_factors = (no_factors *1ll* (cnt + 1))%mod;
            }
            if(curr > 1){
                m[i][curr] = 1;
                no_factors = (no_factors *1ll*  2)%mod;
            }
            answers[i * n + i] = no_factors;
        }
        unordered_map<int,ll>mroot[n];
       // vector<bool>isvisited(n, false);
       // vector<int>parent(n, -1);
        //dfs(0, adj, m, mroot, isvisited, parent);
        solve(0, 0, adj,m,mroot);
        // for(ll i = 0; i < n; i++){
        //     cout << parent[i] << " ";
        // }
        
        // cout << endl;
        int queries, current_ans;
        cin >> queries;
        for(ll i = 0; i < queries; i++){
            cin >> x >> y;
            x --, y --;
            if( x > y) swap(x, y);
            ll current_query = x * n + y;
            if(answers.find(current_query) != answers.end() ){
                cout << answers[current_query] << "\n";
            }
            else if(x == 0){
                current_ans = get_ans(mroot[y]);
                answers[current_query] = current_ans;
                cout << current_ans << "\n";
            }
            else if( x == y){
                current_ans = get_ans(m[x]);
                answers[current_query] = current_ans;
                cout << current_ans << "\n";
               // continue;
            }
            else{
                ll l = lca(x, y);
            //  cout << l << endl;
                unordered_map<int,ll>ru_rv;
                factor_two_number(mroot[x], mroot[y], 1, ru_rv);
                //cout << "case1 \n";
                unordered_map<int,ll>ru_rv_lca;
                factor_two_number(mroot[l], ru_rv, -2 , ru_rv_lca);
            // cout << "case2 \n";
                unordered_map<int,ll>ru_rv_ans;
                factor_two_number(ru_rv_lca, m[l], 1, ru_rv_ans);
            // cout << "case3 \n";
                current_ans = get_ans(ru_rv_ans);
                answers[current_query] = current_ans;
                cout <<  current_ans << "\n";
            }
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int k = 1; k <= t; k ++){
        int n;
        cin >> n;
        string in, out;
        cin >> in >> out;
        vector<vector<int>>adj(n, vector<int>(n, 0));
        vector<int>graph[n];
        for(int i = 0; i < n; i ++){
            for(int j = i - 1; j <= (i + 1); j ++){
                if(j < 0 && j >= n) continue;
                if(i == j){
                    adj[i][j] = 1;
                    continue;
                }
                if(abs(i-j) == 1){
                    if(out[i] == 'Y' && in[j] == 'Y'){
                        adj[i][j] = 1;
                        graph[i].push_back(j);
                    }
                }
            }
        }
        queue<int>q;
        vector<bool>isvisited(n, false);
        for(int i = 0; i < n; i ++){
            q.push(i);
            isvisited[i] = true;
            while(!q.empty()){
                int u = q.front(); q.pop();
                for(int v : graph[u]){
                    if(!isvisited[v]){
                        q.push(v);
                        isvisited[v] = true;
                    }
                }
            }
            for(int j = 0; j < n; j ++){
                if(isvisited[j]) adj[i][j] = 1;
            }
            isvisited.assign(n, false);
        }
        cout << "Case #" << k << ":\n";
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                if(adj[i][j]) cout << "Y";
                else cout << "N";
            }
            cout << "\n";
        }
    }
    return 0;
}
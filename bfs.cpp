#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; //number of vertices.
    cin >> n;
    vector<vector<int> >adj(n); // 
    int m; //number of edges.
    cin >> m;
    for(int i = 0; i < m; i ++){
        int u, v; // u --> v doesn't impy v --> u directed graph
                  // u -- v undirected graph.
        cin >> u >> v;
        //u - v
        adj[u].push_back(v);
        //v - u
        adj[v].push_back(u);
    }
    queue<pair<int, int> >q;  // q type {int, int} 
    q.push({0, 0});
    vector<bool>isvisited(n, false);  // vector<type>vectorname(size, intialisation); vector<int>a(10, -1);
    while(!q.empty()){
        pair<int,int>p = q.front();
        q.pop();
        int u = p.first;  
        int level = p.second; 
        if(isvisited[u]) continue;
        cout << u << "at level: " << level << "\n";
        isvisited[u] = true;
        for(int i = 0; i < adj[u].size(); i ++){
            int v = adj[u][i];
            if(!isvisited[v]){
                q.push({v, level + 1});
            }
        }
    }
    return 0;
}
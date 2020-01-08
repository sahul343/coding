#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    deque<pair<int,int>>q;
    for(int i = 0; i < m; i++){
        while(!q.empty() && q.back().first > a[i]){
            q.pop_back();
        }
        q.push_back(make_pair(a[i],i));
    }
    for(int i = m; i < n; i++){
        cout << q.front().first <<  endl;
        while(i-q.front().second >= m){
            q.pop_front();
        }
        while(!q.empty() && q.back().first > a[i]){
            q.pop_back();
        }
        q.push_back(make_pair(a[i], i));
    }
    cout << q.front().first << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<int,int> > a(n);
    priority_queue<int>q;
    map<int,vector<int> >m;
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
    }
    for(int i = 0; i < n; i++){
        cin >> a[i].second;
        m[a[i].first].push_back(a[i].second);
    }
   
    sort(a.begin(), a.end());
    long long ans = 0;
    while(!m.empty()){
        long long sum = 0;
        long long curr = (*m.begin()).first;
        while(true){
            for(int x: m[curr]){
                sum += x;
                q.push(x);
            }
            m.erase(curr);
            sum -= q.top();
            q.pop();
            ans += sum;
            curr ++;
            if(q.empty()) break;
        }
    }
    cout << ans << endl;
    return 0;
}
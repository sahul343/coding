#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
int main(){
    int n;
    cin >> n;
    string s[n];
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    int len = s[0].size();
    unordered_map<string,pair<int,int>> m;
    for(int i = 0; i < (len); i++){
        string curr = s[0].substr(i,len) + s[0].substr(0,i);
        if(m.find(curr) != m.end()) break;
        m[curr] = mp(0, i);
    }
    int period = m.size();
    for(int i = 0; i < n ; i++){
        if(m.find(s[i]) == m.end()){
            cout << "-1\n";
            return 0;
        }
        m[s[i]].first ++;
    }
    int ans = INT_MAX;
    for(int i = 0; i < len; i++){
        int res = 0;
        string curr = s[0].substr(i,len) + s[0].substr(0,i);
        int offset = m[curr].second;
        for(int j = 0; j  < n ; j++){
            res += (offset - m[s[j]].second +period)%period;
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}
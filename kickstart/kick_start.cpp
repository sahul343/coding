#include<bits/stdc++.h>
using namespace std;
long long solve (){
    string s;
    cin >> s;
    set<int>l, h;
    long long ans = 0;
    int n = s.size();
    for(int i = 3; i <= (n - 5); i ++){
        string curr = s.substr(i , 5);
        if(curr == "START") {
            h.insert(i);
            //cout << i << "\n";
        }
    }
    for(int i = 3; i < n; i ++){
        string curr = s.substr(i - 3, 4);
        if(curr == "KICK"){
           //cout << i << " " << h.size() << "\n";
           ans += h.size();
        }
        if(h.find(i) != h.end()) h.erase(i);
    }
    return ans;
}
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i ++){
        long long cnt = solve();
        cout << "Case #" << i << ": ";
        cout << cnt << "\n";
    }
    return 0;
}
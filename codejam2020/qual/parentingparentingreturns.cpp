#include<bits/stdc++.h>
using namespace std;
bool mycompare(pair<pair<int,int>,int>p1, pair<pair<int,int>,int>p2){
    if(p1.first.first == p2.first.first){
        return p1.first.second < p2.first.second;
    }
    return p1.first.first < p2.first.first;
}
int main(){
    int t;
    cin >> t;
    for(int k = 1; k <= t; k++){
        int n;
        cin >> n;
        vector<pair<int,int> >a(n);
        vector<pair<pair<int,int>,int> >b(2 * n);
        for(int i = 0; i < n; i++){
            cin >> a[i].first >> a[i].second;
            b[2 * i] = make_pair(make_pair(a[i].first, 1), i);
            b[2 * i + 1] = make_pair(make_pair(a[i].second, -1), i);
        }
        sort(b.begin(), b.end(), mycompare);
        int mx = 0, depth = 0;
        for(int i = 0; i < 2 * n; i++){
            depth += b[i].first.second;
            mx = max(mx, depth);
        }
       // cout << mx << endl;
        vector<char>works(n);
        if(mx > 2){
            cout << "Case #" << k <<": IMPOSSIBLE\n";
        }
        else{
            depth = 0;
            string ans;
            bool jfree = true;
            int jwork = -1;
            bool cfree = false;
            int cwork = -1;
            for(int i = 0; i < 2 * n; i++){
                if(b[i].first.second == 1){
                    depth ++;
                    if(jfree){
                        works[b[i].second] = 'J';
                        jfree = false;
                        jwork = b[i].second;
                    }
                    else {
                        works[b[i].second] ='C';
                        cfree = false;
                        cwork = b[i].second;
                    }
                }
                else{
                    if(b[i].second == jwork){
                        jfree = true;
                    }
                    else if(b[i].second == cwork){
                        cfree = false;
                    }
                    depth --;
                }
            }
            for(int i = 0; i < n; i++){
                ans.push_back(works[i]);
            }
            cout << "Case #" << k << ": "<< ans << "\n";
        }
    }
    return 0;
}
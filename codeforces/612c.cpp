#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>p(n);
    int rem[2];
    rem[0] = n/2;
    rem[1] = (n+1)/2;
    int ans = 0;
    
    vector<pair<int,int> >hole;
    for(int i = 0; i < n; i++){
        cin >> p[i];
        if(p[i] == 0){
            p[i] = -1;
        }
        else{
            p[i] = p[i]%2;
            if(p[i] == 0)rem[0]--;
            else rem[1]--;
            hole.push_back(make_pair(i, p[i]));
        }
    }
    if(rem[0]+rem[1] == n && n > 1) ans = 1;
    for(int i = 0; i < n-1; i++){
        if(p[i] != -1 && p[i+1] != -1 ){
            ans += p[i]^p[i+1];
        }
    }
    vector<int>o;
    vector<int>e;
    int anything = 0;
    int n2 = hole.size();
    for(int i = 0; i < n2-1; i++){
        if(hole[i+1].first > hole[i].first+1){
            if(hole[i].second == hole[i+1].second){
                if(hole[i].second == 0){
                    e.push_back(hole[i+1].first-hole[i].first-1);
                }
                else{
                    o.push_back(hole[i+1].first-hole[i].first-1);
                }
                
            }
            else{
                    anything++;
            }
        }
    }
    // cout << o.size() << endl;
    sort(o.begin(), o.end());
    sort(e.begin(), e.end());
    for(int i = 0; i < e.size(); i++){
        if(e[i] <= rem[0]){
            rem[0] -= e[i];
        }
        else {
            ans += 2*(e.size()-i);
            break;
        }
    }
    // cout << ans << endl;
    // cout << rem[1] << endl;
    for(int i = 0; i < o.size(); i++){
        if(o[i] <= rem[1]){
            rem[1] -= o[i];
        }
        else {
            // cout << "i is " << i << endl;
            ans += 2*(o.size()-i);
            // cout << ans << endl;
            break;
        }
    }
    
    // cout << ans << endl;
    ans += anything;
    if(n2 > 0){
        int end_0 = hole.size()-1;
        if(hole[0].second == hole[end_0].second){
            if(rem[hole[0].second] >= (hole[0].first+n-1-hole[end_0].first)){
                int dummy = 1;
            }
            else if(rem[hole[0].second] >= min(hole[0].first , n-1-hole[end_0].first)){
                ans++;
            }
            else{
                ans += 2;
            }
        }
        else{
            if(rem[hole[0].second] < hole[0].first) ans++;
            if(rem[hole[end_0].second] < (n-1-hole[end_0].first))
            ans++;
        }
    }
    
    cout << ans << endl;
    return 0;
}
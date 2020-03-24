#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
int main(){
    int n;
    cin >> n;
    int a[n],b[n],c[n];
    vector<pair<int,int> > f,s,t;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        f.push_back(mp(a[i],i));
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        s.push_back(mp(b[i],i));
    }
    for(int i = 0; i < n; i++){
        cin >> c[i];
        t.push_back(mp(c[i],i));
    }
    unordered_map<int,pair<int,pair<int,int> > >m;
    for(int i = 0; i < n; i++){
        m[i] = mp(a[i],mp(b[i], c[i]));
    }
    vector<bool>isexcellent(n,false);
    int first = 1, second = 1, third = 1;
    sort(f.begin(),f.end());
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    int i = 0, j = 0, k = 0;
    while((i<n && f[i].first <= first)||(j<n && s[j].first <= second)||(k<n && t[k].first <= third)){
        while(i<n && f[i].first <= first){
            auto curr = m[f[i].second];
            second = max(second,curr.second.first-1);
            third = max(third, curr.second.second-1);
            isexcellent[f[i].second] = true;
            i++;
        }
        while(j<n && s[j].first <= second){
            auto curr = m[s[j].second];
            first = max(first,curr.first-1);
            third = max(third, curr.second.second-1);
            isexcellent[s[j].second] = true;
            j++;
        }
         while(k<n && t[k].first <= third){
            auto curr = m[t[k].second];
            first = max(first,curr.first-1);
            second = max(second, curr.second.first-1);
            isexcellent[t[k].second] = true;
            k++;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(isexcellent[i]) ans++;
    }
    cout << ans << "\n";
    return 0;
}
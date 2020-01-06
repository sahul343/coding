#include<bits/stdc++.h>
using namespace std;
bool compare(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2){
    if(p1.first.first == p2.first.first)
        return p1.first.second < p2.first.second;
    return p1.first.first < p2.first.first;
}
int main(){
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int> > a(n);
    vector<pair<pair<int, int>, int> > b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first.first >> a[i].first.second;
        cin >> b[i].first.first >> b[i].first.second;
        a[i].second = i;
        b[i].second = i;
    }
    sort(a.begin(), a.end(), compare);
    sort(b.begin(), b.end(), compare);

    vector<vector<int> >dup1(n);
    vector<vector<int> >dup2(n);
    dup1[0].push_back(a[0].second);
    dup2[0].push_back(b[0].second);
    int j = 0, k = 0;
    vector<pair<int,int> >a1;
    a1.push_back(a[0].first);
    for(int i = 1; i < n; i++){
        pair<int, int> p = a[i].first;
        if(max(p.first, a1[a1.size()-1].first) <= min(p.second, a1[a1.size()-1].second)){
            a1[a1.size()-1].second = max(a1[a1.size()-1].second, p.second);
            dup1[j].push_back(a[i].second);
        }
        else{
            a1.push_back(p);
            j++;
            dup1[j].push_back(a[i].second);
        }
    }
    vector<pair<int,int> >b1;
    b1.push_back(b[0].first);
    for(int i = 1; i < n; i++){
        pair<int, int> p = b[i].first;
        if(max(p.first, b1[b1.size()-1].first) <= min(p.second, b1[b1.size()-1].second)){
            b1[b1.size()-1].second = max(b1[b1.size()-1].second, p.second);
            dup2[k].push_back(b[i].second);
        }
        else{
            b1.push_back(p);
            k++;
            dup2[k].push_back(b[i].second);
        }
    }
    bool flag = true;
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < dup2[i].size() ; j++){
            m[dup2[i][j]] = i;
        }
    }
    for(int i = 0; i < n; i++){
        if(dup1[i].size() == 0)
        continue;
        int index = m[dup1[i][0]];
        if(dup1[i].size() != dup2[index].size()){
            flag = false;
            break;
        }
        
            for(int j = 0; j < dup1[i].size(); j++){
                if(dup1[i][j] != dup2[index][j]){
                    flag = false;
                    break;
                }
            }
        
        if(!flag){
            break;
        }
    }
    if(flag){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
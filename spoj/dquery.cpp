#include<bits/stdc++.h>
using namespace std;
typedef pair<pair<int,int>,pair<int,int> > pp;
#define mp make_pair
bool compare(pp p1,pp p2){
    if(p1.first.first == p2.first.first){
        if (p1.second.second == p2.second.second)
            return p1.second.first < p1.second.first;
        return p1.second.second < p2.second.second;
    }
    else if(p1.second.second == p2.second.second) {
        return p1.first.first < p2.first.first ;
    }
    else{
        return p1.second.second < p2.second.second;
    }
}
void update(vector<int>&t,int idx, int delta, int n){
    for( ; idx < n; idx = idx|(idx+1)){
        t[idx] += delta;
    }
}
int sum(vector<int>&t, int r){
    int ans = 0;
    for( ; r >= 0; r = (r & (r+1))-1){
        ans += t[r];
    }
    return ans;
}
int main(){
    vector<pp>p;
    int n, l, r;
    scanf("%d", &n);
    vector<int>a(n);
    unordered_map<int,int>last;
    vector<int>t(n, 0);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        p.push_back(mp(mp(1,0),mp(a[i],i)));
    }
    int q;
    scanf("%d",&q);
    vector<int>ans(q);
    for(int i = 0; i < q; i++){
        scanf("%d %d",&l, &r);
        l--,r--;
        p.push_back(mp(mp(2,i),mp(l,r)));
    }
    sort(p.begin(),p.end(),compare);
    a.assign(n,0);
    for(int i = 0; i < n+q; i++){
        pp curr = p[i];
        pair<int,int>f = curr.first;
        pair<int,int>s = curr.second;
        if(f.first == 1){
            if(last.find(s.first) == last.end()){
                last[s.first] = s.second;
                a[s.second] = 1;
            }
            else{
                a[last[s.first]] = 0;
                update(t,last[s.first], -1, n);
                last[s.first] = s.second;
                a[s.second] = 1;
            }
            // cout << "curr iteration " << i << " "<< s.second << endl;
            update(t,s.second,1,n);
        }
        else{
            // cout << s.first << " "<< s.second << endl;
            ans[f.second] = sum(t,s.second) - sum(t,s.first - 1);
            // cout << ans[f.second] << endl;
            // for(int i = 0; i < n; i++)
            //     cout << a[i] << " ";
            // cout << endl;
            // cout <<"curr_iteratoin " << i << endl;
        }
    }
    for(int i = 0; i < q; i++){
        printf("%d\n",ans[i]);
    }
    // for(int i = 0; i < n; i++){
    //     cout << a[i] << " ";
    // }
    return 0;
}
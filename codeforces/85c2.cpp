#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
typedef pair<ll,ll> pll;
int n;
int m = 1e9 + 7;
vector<pair<ll, ll> > b;
vector<ll>a;
bool mycompare(pll &p1, pll &p2){
    int i = p1.second;
    ll m1 = a[i] + max(0LL, a[(i+1)%n] - p1.first);
    i = p2.second;
    ll m2 = a[i] + max(0LL, a[(i+1)%n] - p2.first);
    return m1 < m2;
}
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin >> t;
    while( t --){
        cin >> n;
        a.resize(n);
        b.resize(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            cin >> b[i].first;
            b[i].second = i;
        }
        ll ans = 0;
        vector<bool>is_dead(n, false);
        priority_queue<pll, vector<pll>, std::function<bool(pll,pll)>>q(mycompare);
        for(int i = 0; i < n; i++){
            q.push(b[i]);
        }
        while(!q.empty()){
            pll p = q.top();
            q.pop();
            int i = p.second;
            if(!is_dead[i]){
                ans += p.first;
            }
        }
        // sort(b.begin(), b.end(), mycompare);
        // ll ans = 0;
        // for(int i = 0; i < n; i ++){
        //     int curr = b[i].second;
        //     cout << curr << endl;
        //     if(a[curr] <= 0){
        //         a[(curr + 1)%n] -= b[curr].first;
        //     }
        //     else{
        //         ans += a[curr];
        //         a[curr] = 0;
        //         a[(curr + 1)%n] -= b[curr].first;
        //     }
        // }
        // cout << ans << "\n";
    }
    return 0;
}
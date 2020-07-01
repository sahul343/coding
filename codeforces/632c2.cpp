#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
int main(){
    ll n;
    cin >> n;
    ll a[n];
    map<ll,int> m;
    ll ans = 0;
    int curr_ind = 1;
    m[0] = 0;
    ll cum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cum += a[i];
        if(m.find(cum) != m.end()){
          curr_ind = max(curr_ind, m[cum] + 2);
        }
       // cout <<(i + 1) - curr_ind<< " ";
        ans += ((i + 1) - curr_ind) + 1;
        m[cum] = i + 1;
    }
   // cout << "\n";
    cout << ans << "\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>isascent(n, false);
    vector<int>l1;
    vector<int>l2;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        int length;
        cin >> length;
        vector<int>s(length);
        cin >> s[0];
        int mn = s[0];
        int mx = s[0];
        for(int j = 1; j < length; j++){
            cin >> s[j];
            if(s[j] > mn){
                isascent[i] = true;
            }
            mn = min(s[j], mn);
            mx = max(s[j], mx);
        }
        if(!isascent[i]){
        l1.push_back(mn);
        l2.push_back(mx);
        }
        if(isascent[i]) { 
            ans += n;
            // cout << "is ascent "<< i << endl;
        }
    }
    int n1 = l1.size();
    // cout << "n1 is "<< n1 << endl;
   // sort(l1.begin(), l1.end());
    sort(l2.begin(), l2.end());
    for(int i = 0; i < n1; i++){
        int cur1 = l1[i];
        //find numbe of elements > cur1 inl2
        long x = (upper_bound(l2.begin(),l2.end(),cur1)-l2.begin());
        ans += (n-x);
        // cout << x<<endl;
    }
    cout << ans << endl;
    return 0;
}
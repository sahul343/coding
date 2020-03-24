#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;
    while(q--){
        long long n, m;
        cin >> n >> m;
        bool ans  = true;
        
        vector<pair<int,pair<int,int> > > arrival(n);
        for(int i  = 0; i < n; i++){
            cin >> arrival[i].first;
            cin >> arrival[i].second.first >> arrival[i].second.second;
        }
        long long low = m, high  = m;
        int spare = 0;
        long long prev = 0;
        for(int i = 0; i < n; i++){
            long long  l = arrival[i].second.first;
            long long h = arrival[i].second.second;
            spare = arrival[i].first - prev;
            if(l >= low && h <= high){
                low = l;
                high = h;
            }
            else if(l >= low && high <= h && high >= l){
                low = l;
                high = min(h, high + spare);
            }
            else if(l <= low && h<=high && low <=h){
                high = h;
                low = max(l, low - spare);
            }
            else if(l<=low && high <= h){
                low = max(l, low - spare);
                high = min(h, high + spare);
            }
            else if (high <= l ){
                high = min(h, high + spare);
                low  = min(l, low+ spare);
                if( high >= l && high <=h){
                    int x =1;
                    low = l;
                }
                else{
                    ans = false;
                }
            }
            else if(low > h){
                high = max(h, high -spare);
                low = max(l, low -spare);
                if(low >=l && low <= h){
                    high  = h;
                }
                else{
                    ans = false;
                }
            }
            if(low > high){
                ans = false;
                break;
            }
            prev = arrival[i].first;
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
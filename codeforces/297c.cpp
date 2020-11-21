#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    map<int,int>m;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        m[a[i]] += 1;
    }
    unsigned long long ans = 0;
    vector<pair<int,int> > arr;
    for(auto it: m){
        arr.push_back(it);
    }
    int m1 = arr.size();
    for(int i = (m1 - 1); i > 0; i --){
        if(arr[i].second % 2 == 1){
            if(arr[i - 1].first + 1 == arr[i].first && (arr[i - 1].second % 2 == 1)){
                arr[i - 1].second += 1;
            }
            arr[i].second -= 1;
        }
    }
    vector<pair<int,int> > newarr;
    for(int i = 0; i < m1; i ++){
        if(arr[i].second != 0) newarr.push_back(arr[i]);
        //cout << arr[i].first << " " << arr[i].second << "\n";
    }
    int m2 = newarr.size();
    for(int i = (m2 - 1); i >= 0; i --){
	    if(newarr[i].second == 0) continue;
	    // cout << ans << "\n";
        // cout << newarr[i].first << " " << newarr[i].second << "\n";
        ans += (newarr[i].first * 1ull * newarr[i].first) * 1ull * (newarr[i].second/4);
        newarr[i].second %= 4;
        if(newarr[i].second > 0 && (i > 0)){
            ans += (newarr[i].first * 1ull * newarr[i - 1].first);
            newarr[i - 1].second -= 2;
        }
    }
    cout << ans << "\n";
    return 0;
}

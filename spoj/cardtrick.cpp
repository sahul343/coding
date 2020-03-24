#include<bits/stdc++.h>
using namespace std;
void add(vector<int>&t,int idx, int delta, int n){
    for( ;idx < n; idx = idx | (idx+1)){
        t[idx] += delta;
    }
}
int sum(vector<int>&t, int r){
    int ans = 0;
    for( ; r >= 0; r = (r&(r+1))-1 )
        ans += t[r];
    return ans;
}
int find(vector<int>&t, int n,int req){
    int low = 0;
    int high = n-1;
    int mid;
    int ans ;
    while(low <= high){
        mid = low + (high - low)/2;
        if(sum(t, mid) < req){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low ;
}
void solve(int n){
    vector<int>ans(n, 0);
    vector<int>t(n, 0);
    for(int i = 0; i <= n; i++){
        add(t,i,1,n);
    }
    int curr = 0;
    for(int i = 1; i <= n; i++){
        //Finding i+1 the free cell from here.
        //add no of zeros till here.
        //sum up and find

        //No of free cells befor curr.
        int before = sum(t, curr-1);
        //Finding the ith free cell 
        int total = before + (i);
        int req = ((total+1) % (n+1-i) ) ;
        if(req == 0) req = n+1-i;
      //  cout << req << endl;
        curr = find(t, n, req);
       // cout << curr << endl;
        ans[curr] = i;
        add(t, curr, -1, n);
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main(){
    int t;
    cin >> t;
    while( t-- ){
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}
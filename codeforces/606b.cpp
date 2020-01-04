#include<bits/stdc++.h>
using namespace std;
bool isodd(int * a, int n){
    for(int i = 0; i < n; i++){
        if(a[i]%2 == 0)return false;
    }
    return true;
}
int main(){
    int t;
    cin >> t;
    while( t-- ){
        int n;
        cin >> n;
        unordered_map<int, int>m;
        int x;
        for(int i = 0; i < n ; i++){
            cin >> x;
            int cnt = 0;
            while(x%2 == 0){
                x = x/2;
                cnt++;
            }
            if(m.find(x) == m.end()){
                m[x] = cnt;
            }
            else{
                m[x] = max(m[x], cnt);
            }
        }
        unsigned long long ans = 0;
        for(auto i = m.begin(); i != m.end(); i++){
            ans += i->second;
        }
        cout << ans << endl;
        
    }
    return 0;
}
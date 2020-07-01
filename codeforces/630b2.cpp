#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    int f[1001];
    memset(f, -1, sizeof(f));
    vector<bool>isprime(1001, true);
    for(int i = 2; i <= 1001; i++){
        if(isprime[i]){
            for(int j = i * i; j <= 1001; j += i){
                if(f[j] == -1){
                    f[j] = i;
                }
                isprime[j]  = false;
            }
        }
    }
    while( t-- ){
        int n;
        cin >> n;
        int a[n];
        unordered_map<int,int>m;
        int cnt = 0;
        int c[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(m.find(f[a[i]]) == m.end()){
                cnt ++;
                m[f[a[i]]] = cnt;
            }
            c[i] = m[f[a[i]]];
        }
        cout << cnt << endl;
        for(int i = 0; i < n; i++){
            cout << c[i] << " ";
        }
        cout << endl;
        
    }   
}

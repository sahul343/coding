#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t --){
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        set<int>s;
        bool isthere = false;
        int value;
        for(int i = 0; i < n; i ++){
            cin >> a[i];
            s.insert(a[i]);
        }
        for(int i = 0; i < m; i ++){
            cin >> b[i];
            if(s.find(b[i]) != s.end()){
                isthere = true;
                value = b[i];
            }
        }
        if(isthere){
            cout << "YES\n";
            cout << 1 << " " << value << "\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
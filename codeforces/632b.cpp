#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t -- ){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int b[n];
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        map<int,int>m;
        m[0] = 0;
        m[1] = 0;
        m[-1] = 0;
        bool flag = true;
        for(int i = 0; i < n; i++){
            if(a[i] == b[i]){
                m[a[i]]++;
                continue;
            }
            else if(a[i] > b[i] && m[-1] > 0){
                m[a[i]]++;
                continue;
            }
            else if(a[i] < b[i] && m[1] > 0){
                m[a[i]]++;
                continue;
            }
            else{
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t --){
        int n;
        cin >> n;
        int a[n + 2];
        for(int i = 0; i < n; i ++){
            cin >> a[i + 1];
        }
        a[0] = 0;
        a[n + 1] = n + 1;
        stack<int>s;
        bool isalready = true;
        for(int i = 0; i <= n; i ++){
            if(a[i] != i) isalready = false;
        }
        if(isalready){
            cout << "0\n";
            continue;
        }
        int mn = a[0], mx = a[0];
        bool isone = true;
        int cnt = 0;
        for(int i = 0; i <= (n + 1); i ++){
            if(a[i] == i){
                if(!s.empty()){
                    int prev = s.top();
                    
                    if( (i  - prev) > 1 && (mn != (prev + 1) || mx != (i - 1))){
                        isone = false;
                    }
                    if( (i  - prev) > 1 && (mn == prev + 1) && mx == (i - 1) ){
                        cnt ++;
                    }
                }
                s.push(i);
                if( (i + 1) <= n){
                    mn = a[i + 1]; mx = a[i + 1];
                }

            }
            else{
                mn = min(mn, a[i]);
                mx = max(mx, a[i]);
            }
        }
       
        cout << (isone && (cnt <= 1)?"1":"2") << "\n";
    }
    
    return 0;
}
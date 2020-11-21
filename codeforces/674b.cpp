#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t --){
        int n, m;
        cin >> n >> m;
        set<pair< pair<int,int> , pair<int,int> > > s;
        bool flag1 = false, flag2 = false, flag3 = false;
        int a, b, c, d;
        for(int i = 0; i < n; i ++){
            cin >> a >> b >> c >> d;
            if(a == d && b == c) flag1 = true;
            if(b == c) flag2 = true;
            pair<pair<int, int> , pair<int,int> >curr = {{a, c}, {b, d}};
            s.insert({{a, b}, {c, d}});
            if(s.find(curr) != s.end()) flag3 = true;            
        }
        if(m%2 != 0){
            cout << "NO\n";
        }
        else{
            if(m == 2 && flag2) cout << "YES\n";
            else if(flag1) cout << "YES\n";
            else if(flag2 && flag3) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
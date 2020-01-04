#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int f[n+1];
    vector<int>answer(n);
    vector<int>a;
    vector<int>b;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        answer[i]=x;
        if( x > 0 ){
            f[x]++;
        }
        else{
            a.push_back(i+1);
        }
    }
    set<int>s;
    for(int i = 1; i <= n; i++){
        if(f[i] == 0){
            b.push_back(i);
            s.insert(i);
        }
    }
    vector<int>c;
    vector<int>d;
    int rem  = a.size();
    for(int i = 0; i < rem; i++){
        if(s.find(a[i]) != s.end()){
            c.push_back(a[i]);
            s.erase(a[i]);
        }
        else{
            d.push_back(a[i]);
        }
    }
    set<int>::iterator it;
    vector<int>e;
    for(it = s.begin(); it != s.end(); it++){
        e.push_back(*it);
    }


    int n2 = c.size();
    if(n2 > 1){
        for(int i = 0; i < n2; i++){
            answer[c[i]-1] = c[(i+1)%n2];
        }
    }
    else{
        if(n2 == 1){
            d.push_back(c[0]);
            e.push_back(c[0]);
            swap(d[0],d[d.size()-1]);
        }
    }
    int n1 = e.size();
    for(int i = 0; i < n1; i++){
        answer[d[i]-1] = e[i];
    }
    
    for(int i = 0; i < n; i++){
        cout << answer[i] << " ";
    }
    cout << endl;
    cout << n1 << endl;
    cout << n2 << endl;
    return 0;
}
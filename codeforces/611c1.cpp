#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>a;
    vector<int>b;
    vector<int>mapping(n);
    vector<int>f(n,0);
    for(int i = 0; i < n; i++){
        cin >> mapping[i];
        --mapping[i];
        if(mapping[i] == -1) a.push_back(i);
        else{
            f[mapping[i]] = 1;
        }
        
    }
    for(int i = 0; i < n; i++){
        if(f[i] == 0) {
            b.push_back(i);
        }
    }
    vector<int>x;
    vector<int>y;
    vector<int>z;
    for(int i = 0; i < n;i++){
        if(mapping[i] == -1 && f[i] == 0){
            x.push_back(i);
        }
        else if(mapping[i] == -1){
            y.push_back(i);
        }
        else if(f[i] == 0){
            z.push_back(i);
        }
    }
    int n1 = x.size();
    int n2 = y.size();
    if(n1 == 1){
        y.push_back(x[0]);
        z.push_back(x[0]);
        swap(z[0],z[n2]);
        n2++;
    }
    else{
        for(int i = 0; i < n1 ; i++){
            mapping[x[i]] = x[(i+1)%n1];
        }
    }
    for(int i = 0; i < n2; i++){
        mapping[y[i]] = z[i];
    }
    for(int i = 0; i < n; i++){
        cout << mapping[i]+1 <<" ";
    }
    cout << endl;
    return 0;
}
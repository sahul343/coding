#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>a = {1, 2, 3,  5, 6};
    for(auto x: a){
        cout << x << " ";
    }
    cout << "\n";
    cout << a.back() << "\n";
    a.erase(unique(a.begin(), a.end()), a.end());
    auto x  = lower_bound(a.begin(), a.end(), 4);
    auto y =  upper_bound(a.begin(), a.end(), 6) - a.begin();
    cout << *x << " " << y <<"\n";
    return 0;
}
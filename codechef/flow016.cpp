#include<bits/stdc++.h>
using namespace std;
int mygcd(int a, int b){
    return b?mygcd(b, a%b):a;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(a < b) swap(a, b);
        int g = mygcd(a, b);
        long long l = (a/g)*1ll*b;
        cout << g << " "<<l<<endl;
    }
    return 0;
}
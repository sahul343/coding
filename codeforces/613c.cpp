#include<bits/stdc++.h>
using namespace std;
long long mygcd(long long a, long long b){
    if(a < b)swap(a, b);
    while(b){
        long long temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}
int main(){
    long long x;
    cin >> x;
    pair<long long ,long long>p;
    p.first = x;
    p.second = 1;
    long long m = x;
    for(long long  i = 2; i <= sqrt(x); i++){
        if(x%i == 0 && mygcd(i, x/i) == 1){
            if(max(x/i, i) <= max(p.first,p.second)){
                p.first = i;
                p.second = x/i;
            }
        }
    }
    cout << p.first << " "<<p.second << endl;
    return 0;
}
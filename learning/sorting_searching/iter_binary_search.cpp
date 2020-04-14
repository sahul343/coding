#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    int value;
    cin >> value;
    int k = 0;
    for(int b = n/2; b >= 1; b /= 2){
        while( b + k < n && a[b + k] <= value) k += b;
    }
    if(a[k] == value) {
        cout << "value is there at " << k << "\n";
    }
    else{
        cout << "Value not there\n";
    }
    return 0;
}
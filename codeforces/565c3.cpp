#include<bits/stdc++.h>
using namespace std;
int getval(int x){
    if( x == 4) return 0;
    else if(x == 8) return 1;
    else if(x == 15) return 2;
    else if(x == 16) return 3;
    else if(x == 23) return 4;
    else if(x == 42) return 5;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] = getval(a[i]);
    }
    int cnt[6];
    memset(cnt , 0, sizeof(cnt));
    for(int i = 0; i < n; i++){
        cnt[a[i]] += 1;
        for(int j = 0; j < 5; j++){
            if(cnt[j+1] > cnt[j]){
               cnt[j+1] = cnt[j];
            }
        }
    }
    cout << n - 6 * cnt[5] << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
int m = 1e9 + 7;
int main(){
    int t;
    cin >> t;
    while( t --){
        int n, x;
        cin >> n >> x;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a + n);
        ll cum[n];
        int ans  = 0;
        for(int i = n - 1; i >= 0; i --){
            if(i == n-1){
                cum[n - 1] = a[n - 1];
            }
            else{
                cum[i] = a[i] + cum[i + 1];
            }
            if((n - i)*1ll*x > cum[i]){
                break;
            }
            ans = n - i;
        }
        cout << ans << endl;   
    }
    return 0;
}
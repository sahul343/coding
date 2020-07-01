#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while( t --){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++){
            cin >> A[i];
        }
        long long ans = 0;
        for(int i = 0; i < n; i++){
            int start = i, end = i;
            while(start > 0){
                if(A[start] >= A[start - 1]){
                    start --;
                }
                else{
                    break;
                }
            }
            while(end < (n - 1)){
                if(A[end] > A[end + 1]){
                    end ++;
                }
                else{
                    break;
                }
            }
            int length = min(i - start, end - i);
            ans += length;
        }
        cout << ans << "\n";
    }
    return 0;
}
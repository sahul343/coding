#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 8;
    int a[] = {-1, 2, 4, -3, 5, 2, -5, 2};
    int ans = a[0];
    for(int i = 0; i < n ; i++){
        for(int j = i; j < n; j++){
            int sum = 0;
            for(int k = i; k <= j; k ++){
                sum += a[k];
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << "\n";
    return 0;
}
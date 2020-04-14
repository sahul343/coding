#include<bits/stdc++.h>
using namespace std;
int upper(vector<int>&a, int low, int val){
    int start = low, end = a.size()  - 1, ans = -1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(a[mid] >= val){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}
int exact_upper(vector<int>&a, int i, int val){
    int start = i, end = a.size() -1, ans = -1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(a[mid] == val){
            ans = mid;
            start = mid + 1;
        }
        else if(a[mid] > val){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}
int main(){
    int t, n;
    cin >> t;
    while( t --){
        int n;
        cin >> n;
        int a[n];
        vector<int>zeros(n+1, 0);
        vector<int>cum(n+1, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            zeros[i + 1] = zeros[i];
            if(a[i] == 0){
                zeros[i + 1]++;
            }
            a[i] = abs(a[i]);
            while(a[i] && a[i]%2 == 0){
                a[i] /= 2;
                cnt ++;
            }
            cum[i + 1] = cnt;
        }
        long long ans = 0;
        for(int i = 1; i <= n; i++){
            //Find least index j >= i such that cum[j] >= 2 + cum[i - 1]
            //Find least j >= i such that zeros[j] >= zeros[i - 1] + 1.
            //Find greatest j such that cum[j] == cum[i - 1].
            int j1 = upper(cum, i, cum[i-1] + 2);
            int j2 = upper(zeros, i, zeros[i - 1] + 1);
            int j3 = exact_upper(cum, i, cum[i - 1]);
            int j = max(j1, j2);
            if(j == -1){
                if(j3 != -1){
                    ans += j3 - (i - 1);
                }
            }
            else{
                ans += n - (j - 1);
                if(j3 != -1){
                    ans += j3 - (i - 1);
                    if(j3 >= j){
                        ans -= (j3 - j) + 1;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
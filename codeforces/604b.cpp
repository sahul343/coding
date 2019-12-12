#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        vector<int>f(n, 0);
        int j = 0;
        int ind = 0;
        for(int i = 0; i< n ; i++){
            cin >> a[i];
            if(a[i] == 1)ind = i;
        }
        int k = ind + 1;
        int l = ind - 1;
        vector<int>ans(n,0);
        ans[0]=1;
        f[0]=1;
        while(k<n || l >= 0){
            if(k<n && l >=0 && a[k]<a[l]){
                f[a[k]-1]=1;
                k++;
            }
            else if(k<n && l >=0 && a[k]>a[l]){
                f[a[l]-1]=1;
                l--;
            }
            else if(k<n){
                f[a[k]-1]=1;
                k++;
            }
            else if(l>=0){
                f[a[l]-1]=1;
                l--;
            }
            while((j+1) < n && f[j] == f[j+1]){
                j++;
            }
            if(k-l-1 == j+1){
                ans[j]=1;
            }
        }
        for(int i = 0; i< n; i++){
            cout<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    FILE *f1 = fopen("input.txt","r");
    FILE *f2 = fopen("output.txt","w");
    fscanf(f1,"%d",&n);
    int a[n];
    for(int i = 0; i < n; i++){
        fscanf(f1,"%d",&a[i]);
    }
    int cnt[n];
    int count = 0, zerocnt = 0;
    int zeros[n];
    for(int i = 0; i < n; i++){
        if(a[i] == 0) zerocnt ++;
        if(a[i] < 0) count ++;
        cnt[i] = count;
        zeros[i] = zerocnt;
    }
    // for(int i = 0; i < n; i++){
    //     cout << cnt[i]  << endl;
    // }
    int ans = n;
    for(int i = 1; i < n ; i++){
        int pos = (i - cnt[i - 1]) - zeros[i-1];
        int neg = (cnt[n-1] - cnt[i - 1]) ;
        ans = min(ans, pos + neg);
       // cout << pos << " " << neg << endl;
    }
    ans += zerocnt;
    fprintf(f2,"%d\n", ans);
    fclose(f1);
    fclose(f2);
    return 0;
}
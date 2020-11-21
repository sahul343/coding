#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while( t --){
        int n, k, w;
        cin >> n >> k >> w;
        int s[n];
        int h[n];
        for(int i = 0; i < k; i ++){
            cin >> s[i];
        }
        int s1, s2, s3, s4;
        cin >> s1 >> s2 >> s3 >> s4;
        for(int i = 0; i < k; i ++){
            cin >> h[i];
        }
        int h1, h2, h3, h4;
        cin >> h1 >> h2 >> h3 >> h4;
        for(int i = k; i < n; i ++){
            s[i] = ( (s1 * s[i - 2] + s2 * s[i - 1] + s3) % s4 ) + 1;
            h[i] = ( (h1 * h[i - 2] + h2 * h[i - 1] + h3) % h4 ) + 1;
        }
        int ans = 1;
        for(int i = 0; i < n; i ++){
            
        }
    }
    return 0;
}
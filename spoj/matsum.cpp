#include<bits/stdc++.h>
using namespace std;
char s[10];
int t[1025][1025];
int a[1025][1025];
int sum( int x, int y){
    int ans = 0;
    for(int i = x; i >= 0; i = (i & (i+1))-1){
        for(int j = y; j >= 0; j = (j&(j+1))-1){
            ans += t[i][j];
        }
    }
    return ans;
}
void update(int n, int x, int y, int delta){
    for(int i = x; i <n ; i = i|(i+1)){
        for(int j = y; j < n; j = j|(j+1)){
            t[i][j] += delta;
        }
    }
}
int main(){
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t1, n;
    scanf("%d", &t1);
    while( t1-- ){
       scanf("%d",&n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                a[i][j] = 0;
                t[i][j] = 0;
            }
        }
        int x1, y1, x2, y2, num;
        while(1){
            scanf("%s",s);
            if(strcmp(s,"END") == 0) break;
            else if(strcmp(s,"SET") == 0){
                scanf("%d %d %d",&x1, &y1, &num);
            // cin >> x1 >> y1 >> num;
                update( n, x1, y1, num - a[x1][y1] );
                a[x1][y1] = num;

            }
            else{
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            // cin >> x1 >> y1 >> x2 >> y2;
                int ans = sum( x2, y2) + sum( x1 - 1, y1 - 1) - sum( x1 - 1, y2) -sum( x2, y1 - 1);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
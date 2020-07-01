#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int f1[10],f2[10];
    memset(f1, 0, sizeof(f1));
    memset(f2, 0, sizeof(f2));
    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 0; i < n; i++){
        f1[s1[i] - '0']++;
    }
    for(int i = 0; i < n; i++){
        f2[s2[i] - '0']++;
    }
    int mn = 0, mx = 0;
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j < f1[i]; j++){
            for(int k = 0; k <= 9; k++){
                int curr = (i+k)%10;
                if(f2[curr] == 0) continue;
                f2[curr]--;
                if(curr < i) mn ++;
                break;
            }
        }
    }
    memset(f2, 0, sizeof(f2));
    for(int i = 0; i < n; i++){
        f2[s2[i] - '0']++;
    }
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j < f1[i]; j++){
            for(int k = 0; k <= 9; k++){
                int curr = (i+1+k)%10;
                if(f2[curr] == 0) continue;
                f2[curr] --;
                if(curr > i) mx ++;
                break;
            }
        }
    }
    cout << mn << "\n" << mx << "\n";
    return 0;
}
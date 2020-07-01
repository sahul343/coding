#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair;
#define REP(i, a, b) for(int i = a; i <= b; i++)
int m = 1e9 + 7;
int cnt = 0;
vector<int>col;
bool ispossible(int y, int c){
    for(int i = 0; i < y; i++){
        if(abs(i - y) == abs(col[i] - c) || col[i] == c) {
            return false;
        }
    }
    return true;
}
void search(int y, int n){
    if(y == n){
        cnt ++;
        for(int i = 0; i < n; i++){
            cout << col[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int c = 0; c < n; c ++){
        if(ispossible(y, c)){
            col[y] = c;
            search(y + 1, n);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    col.assign(n , -1);
    search(0, n);
    cout << cnt << "\n";
    return 0;
}
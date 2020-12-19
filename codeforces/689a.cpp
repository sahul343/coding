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
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while( t --){
        string s;
        int n, k;
        cin >> n >> k;
        for(int i = 0; i < n/3; i ++){
            cout << "abc";
        }
        if(n%3 == 1) cout << "a";
        else if(n%3 == 2) cout << "ab";
        cout << "\n";
    }
    return 0;
}
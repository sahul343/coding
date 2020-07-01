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
    int n;
    cin >> n;
    vector<int>permute(n);
    for(int i = 1; i <= n; i++){
        permute[i - 1] = i;
    }
    do{
        REP(i, 0, n - 1){
            cout << permute[i] << " ";
        }
        cout << "\n";
    }while(next_permutation(permute.begin(), permute.end()));
    return 0;
}
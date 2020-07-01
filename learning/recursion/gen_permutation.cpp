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
vector<bool>chosen;
vector<int>permutation;
void gen_permutation(int n){
    if(permutation.size() == n){
        REP(i, 0, n-1){
            cout << permutation[i] << " ";
        }
        cout << "\n";
    }
    else{
        for(int i = 1; i <= n; i++){
            if(chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            gen_permutation(n);
            chosen[i] =  false;
            permutation.pop_back();
        }
    }
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    chosen.assign(n, false);
    gen_permutation(n);
    return 0;
}
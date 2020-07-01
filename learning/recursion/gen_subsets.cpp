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
vector<int>subset;
void subset_gen(int k, int n){
    if(k == n){
        for(int i = 0; i < subset.size(); i++){
            cout << subset[i] <<" ";
        }
        cout << "\n";
        return;

    }
    subset.push_back(k + 1);
    subset_gen(k + 1, n);
    subset.pop_back();
    subset_gen(k + 1, n);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << "Printing all subset of a set of "<<n << " elements\n";
    subset_gen(0, n);
    return 0;
}
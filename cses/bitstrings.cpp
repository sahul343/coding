#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int ans = 1;
	int mod = 1e9 + 7;
	int p = 2;
	while(n){
		if(n & 1){
			ans = (ans * 1ll * p) % mod;
		}
		n /= 2;
		p = (p * 1ll * p) % mod;
	}
	cout << ans << "\n";
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int p = 5;
	int ans = 0;
	while(n/p >= 1){
		ans += n/p;
		p *= 5;
	}
	cout << ans << "\n";
	return 0;
}
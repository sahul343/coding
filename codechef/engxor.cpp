#include<bits/stdc++.h>
using namespace std;
bool oddones(int n){
	int cnt = 0;
	int p = 1;
	while(n){
		if(n & 1) cnt ++;
		n /= 2;
	}
	return cnt%2 == 1;
}
int main(){
	int t, n, q, p;
	int odd, even;
	cin >> t;
	while( t-- ){
		odd = 0;
		even = 0;
		cin >> n >> q;
		int a[n];
		for(int i = 0; i < n; i++) 
			cin >> a[i];
		for(int i = 0; i < n; i++){
			if(oddones(a[i])) odd ++;
			else even ++;
		}
		for(int i = 0; i < q; i++){
			cin >> p;
			if(oddones(p)) cout << odd << " " << even << "\n";
			else cout << even << " " << odd << "\n";
		}

	}
	return 0;
}
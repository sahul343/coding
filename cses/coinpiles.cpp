#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while( t -- ){
		int a, b;
		cin >> a >> b;
		if(min(a, b) * 2 >= max(a,b) && (a + b) % 3 == 0){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}
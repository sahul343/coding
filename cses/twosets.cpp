#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	if(n % 4 == 0 || (n + 1) % 4 == 0){
		cout << "YES\n";
		if(n%4 == 0){
			cout << n/2 << "\n";
			for(int i = 1; i <= n/2; i += 2){
				cout << i << " " << (n + 1 - i) << " ";
			}
			cout << "\n";
			cout << n/2 << "\n";
			for(int i = 2; i <= n/2; i += 2){
				cout << i << " " << (n + 1 - i) << " ";
			}
			cout << "\n";
		}
		else{
			cout << n/2 << "\n";
			for(int i = 1; i < n/2; i += 2){
				cout << i << " " << (n - i) << " ";
			}
			cout << n << "\n";
			cout << (n + 1)/2 << "\n";
			for(int i = 2; i <= n/2; i += 2){
				cout << i << " " << (n - i) << " ";
			}
			cout << n/2 << " " << (n - n/2) << "\n";
		}
	}
	else{
		cout << "NO\n";
	}
	return 0;
}
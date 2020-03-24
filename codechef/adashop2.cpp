#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while( t-- ){
		int r, c;
		cin >> r >> c;
		int cnt = 25;
		if( r == c  && r != 1) {
			cnt ++;
		}
		else if( r != c ){
			cnt += 2;
		}
		cout << cnt << endl;
		if( cnt == 26){
			cout << "1 1\n";
		}
		if(cnt == 27){
			cout << (r+c)/2 << " " << (r+c)/2 << endl;
			cout << "1 1\n";
		}

		for(int i = 2; i <= 4; i++){
			cout << i << " " << i << endl;
			cout << 2*i-1 << " " << 1 << endl;
			cout << 1 << " " << 2*i - 1 << endl;
			cout << i << " " << i << endl;
		}
		for(int i = 5; i <8; i++){
			cout << i << " " << i << endl;
			cout << 8 << " " << 2*i - 8<< endl;
			cout << 2*i - 8 << " " << 8 << endl;
			cout << i << " " << i << endl;
		}
		cout << "8 8\n";
	}
	return 0;
}
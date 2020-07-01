#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int fre[26];
	memset(fre, 0, sizeof(fre));
	int n = s.size();
	for(int i = 0; i < n ; i ++){
		fre[s[i] - 'A'] ++;
	}
	int odds = 0;
	int odds_pos = -1;
	for(int i = 0; i < 26; i ++){
		if(fre[i] % 2 == 1) {
			odds ++;
			odds_pos = i;
		}

	}
	//cout << odds << " " << n << " \n";
	if((n%2 == 1 && odds == 1) || (n%2 == 0 && odds == 0)){
		string front, back;
		for(int i = 0; i < 26; i++){
			for(int j = 0; j < fre[i]/2; j ++){
				front.push_back('A' + i);
				back.push_back('A' + i);
			}
		}
		if(odds == 1){
			front.push_back('A' + odds_pos);
		}
		reverse(back.begin(), back.end());
		front += back;
		cout << front << "\n";
	}
	else{
		cout << "NO SOLUTION\n";
	}
	return 0;
}
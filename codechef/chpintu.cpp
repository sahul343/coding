#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while( t-- ){
		int n, m;
		cin >> n >> m;
		vector<bool>isthere(m, false);
		vector<int>cost(m, 0);
		
		vector<pair<int,int> > cat(n);
		for(int i = 0; i < n; i++){
			cin >> cat[i].first;
		}
		for(int i = 0; i < n; i++){
			cin >> cat[i].second;
		}
		int ans = INT_MAX;
		for(int i = 0; i < n; i++){
			isthere[cat[i].first - 1] = true;
			cost[cat[i].first - 1] += cat[i].second;
		}
		for(int i = 0; i < m; i++){
			if(isthere[i])
			ans = min(ans, cost[i]);
		}
		cout << ans << endl;

	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<string>grid(n);
    vector<pair<int,int> >row(10, {-1, -1}), col(10, {-1, -1});
    for(int i = 0; i < n; i ++) {
        cin >> grid[i];
    }

    vector<vector<pair<int,int> > >rowDigit(n, vector<pair<int,int> >(10, {-1, -1}));
    vector<vector<pair<int,int> > >colDigit(n, vector<pair<int,int> >(10, {-1, -1}));

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            int digit = grid[i][j] - '0';
            if(row[digit].first == -1){
                row[digit] = {i, i};
            }
            else{
                row[digit].first = max(row[digit].first, i);
                row[digit].second = min(row[digit].second, i);
            }

            if(col[digit].second == -1){
                col[digit] = {j, j};
            }
            else {
                col[digit].first = max(col[digit].first, j);
                col[digit].second = min(col[digit].second, j);
            }

            if(rowDigit[i][digit].first = -1){
                rowDigit[i][digit] = {j, j};
            }
            else {
                rowDigit[i][digit].first = max(rowDigit[i][digit].first, j);
                rowDigit[i][digit].second = min(rowDigit[i][digit].second, j);
            }

            if(colDigit[j][digit].first = -1){
                colDigit[j][digit] = {i, i};
            }
            else {
                colDigit[j][digit].first = max(colDigit[j][digit].first, i);
                colDigit[j][digit].second = min(colDigit[j][digit].second, i);
            }
        }
    }
    
    vector<int>area(10, 0);
    
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            int digit = grid[i][j] - '0';
            int base1 = max(j, n - (j + 1));
        
            int a1 = max( base1 * max(abs(row[digit].first - i), abs(row[digit].second - i)), area[digit]);
            int base2 = max(i, n - (i + 1));
            int a2 = max( base2 * max(abs(col[digit].first - j), abs(col[digit].second - j)), area[digit]);

            area[digit] = max(area[digit], max(a1, a2));
            // cout << i << " " << j << " " << digit << " " << base1 << " " << a1 << " " << base2 << " " << a2 << " " << area[digit] << "\n";
        }
    }

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < 10; j ++){
            int a1 = (rowDigit[i][j].first - rowDigit[i][j].second) * (max(abs(i - row[j].first), abs(i - row[j].second)));
            int a2 = (colDigit[i][j].first - colDigit[i][j].second) * (max(abs(i - col[j].first), abs(i - col[j].second)));
            //cout << a1 << " " << a2 << "\n";
            area[j] = max(area[j], max(a1, a2));
            
        }
    }

    for(int i = 0; i < 10; i ++) {
        cout << area[i] << " ";
    }
    cout << "\n";
}
int main() {
    int t;
    cin >> t;
    while( t -- ) {
        solve();
    }
    return 0;
}
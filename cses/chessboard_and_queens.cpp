#include<bits/stdc++.h>
using namespace std;
bool valid(vector<int>&positions, int row, int col){
    for(int i = 0; i < row; i ++){
        if(positions[i] == col) return false;
        if(abs(row - i) == abs(col - positions[i])) return false;
    }
    return true;
}
void solve(vector<string>&board, int &ans, int curr_row, vector<int>&positions){
    if(curr_row == 8){
        ans ++;
        return;
    }
    for(int i = 0; i < 8; i ++){
        if(board[curr_row][i] == '.' && valid(positions, curr_row, i)){
            positions[curr_row] = i;
            solve(board, ans, curr_row + 1, positions);
        }
    }
}
int main(){
    vector<string>board(8);
    for(int i = 0; i < 8; i ++){
        cin >> board[i];
    }
    vector<int>postions(8);
    int ans = 0, curr_row = 0;
    solve(board, ans, curr_row, postions);
    cout << ans << "\n";
    return 0;
}
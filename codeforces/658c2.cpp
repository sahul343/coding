#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int start = 0, end = n - 1, flips = 0, curr_pos = n - 1;
        vector<int>operations;
        while(curr_pos >= 0){
            char current =  '0' + ( ( a[end] - '0' ) + flips ) % 2;
            if(current == b[curr_pos]){
                int x = 1;
                if(start < end) end --;
                else end ++;
            }
            else{
                char start_char = '0' + (a[start] - '0' + flips)%2;
                if(start_char != b[curr_pos]){
                    operations.push_back(curr_pos + 1);
                }
                else{
                    operations.push_back(1);
                    operations.push_back(curr_pos + 1);
                }
                if(start < end) start ++;
                else start --;
                flips = (flips + 1) % 2;
                swap(start, end);
            }
            curr_pos --;
        }
        cout << operations.size() << " ";
        for(int x: operations){
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
string do_the_process(string s, int till_here){
    string begining;
    for(int i = 0; i < till_here; i ++){
        begining.push_back(s[i] == '0'?'1':'0');
    }
    reverse(begining.begin(), begining.end());
    for(int i = till_here; i < s.size(); i ++){
        begining.push_back(s[i]);
    }
    return begining;
}
int main(){
    int t;
    cin >> t;
    while( t --){
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int current_pos = a.size() - 1;
        vector<int>operations;
        while(current_pos >= 0){
            if(a[current_pos] == b[current_pos]) {
                current_pos --; 
                continue;
            }
            else{
                if(a[0] != b[current_pos]){
                    a = do_the_process(a, current_pos + 1);
                    operations.push_back(current_pos + 1);
                }
                else{
                    operations.push_back(1);
                    a = do_the_process(a, 1);
                    operations.push_back(current_pos + 1);
                    a = do_the_process(a, current_pos + 1);
                }
            }
            current_pos --;
        }
        cout << operations.size() << " ";
        for(int x: operations){
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
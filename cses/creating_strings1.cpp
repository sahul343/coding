#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string>a;
    do
    {
        a.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    
    cout << a.size() << "\n";
    for(auto str: a){
        cout << str << "\n";
    }
    

    return 0;
}
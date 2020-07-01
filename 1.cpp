#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool isconstant(char c){
    if(c == '[' || c == ']') return true;
    else return false;
}
int main(){
    map<char,string>rules;
    rules['A'] = "A[B]";
    rules['B'] = "B[C]";
    rules['C'] = "C[A]";
    string s = "AB";
    int number_iterations = 5;
    cout << "N = 1  => "<< s << "\n";
    for(int i = 2; i <= number_iterations; i++){
        int n = s.size();
        string result;
        for(int j = 0; j < n; j++){
            if(isconstant(s[j])) {
                result.push_back(s[j]);
            }
            else{
                result += rules[s[j]];
            }
        }
        cout <<"N = "<<i<<"  => " << result << "\n"; 
        s = result;
    }
    return 0;
}
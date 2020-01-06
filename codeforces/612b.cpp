#include<bits/stdc++.h>
using namespace std;
string other(string &s1, string &s2){
    string s;
    int n = s1.size();
    vector<char>a(2);
    for(int i = 0; i < n; i++){
        a[0]=s1[i];
        a[1]=s2[i];
        sort(a.begin(), a.end());
        if(s1[i] == s2[i]) s.push_back(s1[i]);
        else if(a[0] == 'E' && a[1] == 'S'){
            s.push_back('T');
        }
        else if(a[0] == 'E' && a[1] == 'T'){
            s.push_back('S');
        }
        else if(a[0] == 'S' && a[1] == 'T'){
            s.push_back('E');
        }
    }
    return s;
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<string>card(n);
    unordered_map<string, int>m;
    for(int i = 0; i < n; i++){
        cin >> card[i];
        if(m.find(card[i]) == m.end()){
            m[card[i]] = 0;
        }
        m[card[i]]++;
    }
    long long ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            string s1 = card[i];
            string s2 = card[j];
            string s3 = other(s1, s2);
            ans += m[s3];
            // cout << " The current one is \n";
            // cout << s1 << endl;
            // cout << s2 << endl;
            // cout << s3 << endl;
            // cout << m[s3] << endl;
            if(s1 == s3)ans--;
            if(s2 == s3)ans--;
        }
    }
    ans /= 3;
    cout << ans << endl;
    return 0;
}
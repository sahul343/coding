#include<bits/stdc++.h>
using namespace std;
bool ispalindrome(string s)
{
    int i = 0, j = s.size() -1;
    while(i<j){
        if(s[i]!=s[j])return false;
        i++,j--;
    }
    return true;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<string>s(n);
    unordered_map<string,int>m1;
    
    for(int i = 0; i < n; i++){
        cin >> s[i];
        if(m1.find(s[i]) == m1.end()){
            m1[s[i]]=0;
        }
        m1[s[i]]++;
    }

    string front;
    string back;
    string middle;
    string ans;
    for(int i = 0; i < n; i++){
        string curr = s[i];
        string rev = s[i];
        reverse(rev.begin(),rev.end());
        if(m1[curr] > 0 && (m1.find(rev)!=m1.end()&&m1[rev]>0) &&curr!=rev ){
            m1[curr]--;
            m1[rev]--;
            front = curr+front;
            back = back + rev;
        }
        if(m1[curr] > 1 &&curr==rev ){
            m1[curr]--;
            m1[rev]--;
            front = curr+front;
            back = back + rev;
        }
    }

    for(int i = 0; i < n; i++){
        if(m1[s[i]] > 0 && ispalindrome(s[i])){
            middle = s[i];
            break;
        }
    }
    ans = front + middle + back;
    cout << ans.size() << endl;
    cout << ans << endl;
    return 0;
}
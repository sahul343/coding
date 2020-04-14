#include<bits/stdc++.h>
using namespace std;
typedef  pair<long long, long long> pii;
const int m = 998244353;
typedef struct prob
{
    int f,s,t,fo;
}prob;

#define ll long long
#define mp make_pair
ll mypow(ll a, ll b){
    if(b == 0)return 1;
    if(b%2 == 1)return ((mypow((a*a)%m, b/2)%m) * a)%m;
    else return (mypow((a*a)%m, b/2))%m;
}
ll mygcd(ll a, ll b){
    if(a < b)swap(a, b);
    ll temp;
    while( b ){
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
string in_post(string a){
    int n = a.size();
    stack<char>s;
    string ans;
    for(int i = 0; i < n; i++){
        if(a[i] == '('){
            s.push('(');
        }
        else if(a[i] == ')'){
            while(!s.empty() && s.top() != '('){
                ans.push_back(s.top());
                s.pop();
            }
            if(s.top() == '('){
                s.pop();
            }
        }
        else if(a[i] == '#'){
            ans.push_back('#');
        }
        else{
            s.push(a[i]);
        }
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
pii calc(pii p1, pii p2, char c){
    pii p;
    if(c == '&'){
        p.second = p1.second * p2.second;
        p.first = p1.first * (p2.first + p2.second) + p1.second * p2.first;
    }
    else if(c == '|'){
        p.first = p1.first + p2.first;
        p.second = p1.second * (p2.first + p2.second) + p1.first * p2.second;
    }
    else if(c == '^'){
        p.first = p1.first * p2.first + p1.second * p2.second;
        p.second = p1.first * p2.second + p1.second * p2.first;
    }
    ll g = mygcd(p.first, p.second);
    // p.first /= g;
    // p.second /= g;
    p.first = p.first % m;
    p.second = p.second % m;
    return p;
}
ll get_ans(ll p, ll q){
    return (p * mypow(q, m-2))%m;
}
int main(){
    int t;
    string s;
    cin >> t;
    while( t-- ){
        cin >> s;
        s = in_post(s);
       // cout << s << endl;
        stack<pii>p;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '#'){
                p.push(mp(1,1));
            }
            else{
                pii p1 = p.top();
                p.pop();
                pii p2 = p.top();
                p.pop();
                p.push(calc(p1,p2,s[i]));
            }
        }
        pii final_p = p.top();
        p.pop();
        ll a = final_p.first * final_p.first;
        ll b = final_p.second * final_p.second;
        ll c = final_p.first * final_p.second;
        ll d = final_p.second * final_p.first;
        ll denom = (final_p.first + final_p.second);
        //cout << a << " " << b << " " << c << " " << d << endl;
        cout << get_ans(a, (denom * denom)%m) << " "<<get_ans(b, (denom * denom)%m) << " ";
        cout << get_ans(c, (denom * denom)%m) << " "<<get_ans(d, (denom * denom)%m) << "\n";
    }
    return 0;
}
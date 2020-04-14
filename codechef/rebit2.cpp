#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const int m = 998244353;
typedef struct prob
{
    ll z,o,a,A;
}prob;
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
prob calc_or(prob &p1,prob &p2){
    prob ans;
    ans.z = p1.z  * p2.z;
    ans.o = p1.o * p2.z + p1.o *p2.o + p1.o *p2.a +p1.o * p2.A +  p2.o *p1.z +p2.o * p1.a +p2.o * p1.A + p1.a * p2.A + p1.A * p2.a;
    ans.a = p1.a * p2.a + p1.z * p2.a + p1.a * p2.z;
    ans.A = p1.A * p2.A + p1.z * p2.A + p1.A * p2.z;
    return ans;
}
prob calc_xor(prob &p1, prob &p2){
    prob ans;
    ans.z = p1.z * p2.z + p1.o * p2.o + p1.a * p2.a + p1.A * p2.A;
    ans.o = p1.z * p2.o + p1.o * p2.z + p1.a * p2.A + p1.A * p2.a;
    ans.a = p1.z * p2.a + p1.o * p2.A + p1.a * p2.z + p1.A * p2.o;
    ans.A = p1.z * p2.A + p1.o * p2.a + p1.a * p2.o + p1.A * p2.z;
    return ans;
}
prob calc_and(prob &p1, prob &p2){
    prob ans;
    ans.z = p1.z * (p2.z + p2.o + p2.a + p2.A) + p2.z * (p1.a + p1.o + p1.A) + p1.A * p2.a + p1.a * p2.A;
    ans.o = p1.o * p2.o;
    ans.a = p1.o * p2.a + p1.a * p2.a + p1.a * p2.o;
    ans.A = p1.A * p2.A + p1.a * p2.o + p1.o * p2.A;
    return ans;
}
prob normalise(prob p){
    p.z = p.z %m;
    p.o = p.o %m;
    p.a = p.a %m;
    p.A = p.A %m;
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
        stack<prob>p;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '#'){
                prob curr;
                curr.z = 1, curr.o = 1, curr.a = 1, curr.A = 1;
                p.push(curr);
            }
            else if(s[i] == '&'){
               prob p1 = p.top();
               p.pop();
               prob p2 = p.top();
               p.pop();
               p.push(normalise(calc_and(p2, p1)));
            }
            else if(s[i] == '|'){
               prob p1 = p.top();
               p.pop();
               prob p2 = p.top();
               p.pop();
               p.push(normalise(calc_or(p2, p1)));
            }
            else if(s[i] == '^'){
               prob p1 = p.top();
               p.pop();
               prob p2 = p.top();
               p.pop();
               p.push(normalise(calc_xor(p2, p1)));
            }
        }
        prob final_p = p.top();
        p.pop();
        ll denom = (final_p.z + final_p.o + final_p.a + final_p.A)%m;
        //cout << a << " " << b << " " << c << " " << d << endl;
        cout << get_ans(final_p.z, denom) << " "<<get_ans(final_p.o, denom) << " ";
        cout << get_ans(final_p.a, denom) << " "<<get_ans(final_p.A, denom) << "\n";
    }
    return 0;
}
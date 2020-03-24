#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n1 = 1e6+1;
    vector<bool>is_prime(n1+1, true);
    vector<long long>failing(n1+1, -1);
    is_prime[0] = is_prime[1] = false;
    for (long long i = 2; i <= n1; i++) {
        if (is_prime[i] && (long long)i * i <= n1) {
            for (long long j = i * i; j <= n1; j += i){
                is_prime[j] = false;
                failing[j] = i;
            }
        }
    }
    long long t;
    cin >> t;
    while( t-- ){
        long long n;
        cin >> n;
        
        bool flag = true;
        for(long long i = sqrt(n); i >=2; i--){
            if(n%i == 0 ){
                
                    long long x1 = 0, x2 =0 , x3 =0;
                    if(is_prime[i] == false){
                        x1 = failing[i], x2 =(i/failing[i]),x3=(n/i);
                    
                    }
                    else if(n/i <= n1 && is_prime[n/i] == false) {
                        x1= failing[n/i] ,x2=((n/i)/failing[n/i]), x3=i;
                        
                    }
                    if( x1 != x2 && x2!=x3 && x3!=x1){
                        cout << "YES\n";
                        cout << x1<<" "<<x2<<" "<<x3<<endl;
                        flag = false;
                        break;
                    }
                
            }
        }
        if(flag)
        cout << "NO" << endl;
    }
    return 0;
}
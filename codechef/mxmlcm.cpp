#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<bool>isprime(10001, true);
    isprime[0] = false;
    isprime[1] = false;
    for(int i = 2; i <= 10000; i++){
        if(isprime[i]){
            for(int j = i * i; j <= 10000; j += i){
                isprime[j] = false;
            }
        }
    }
    vector<int>primes;
    for(int i = 2; i <= 10000; i++){
        if(isprime[i]) 
        {
            primes.push_back(i);
           // cout << i << " ";
        }
    }
  //  cout << endl;
    int t;
    cin >> t;
    while( t-- ){
        int n, m, x;
        cin >> n >> m;
        vector<bool>isvisited(m+1, false);
        long long lcm ;
        for(int i = 0; i < n; i++){
           cin >> x;
           for(int j = 0; j <= primes.size() ; j++) {
               if(primes[j] < m ) break;
               if(x%primes[j] == 0 && !isvisited[primes[j]]){
                   for(int k = primes[j]; k <= m; k += primes[j]){
                       isvisited[k] = true;
                   }
               }
           }
        }
        for(int i = m; i >= 1; i--){
            if(!isvisited[i]) {
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}
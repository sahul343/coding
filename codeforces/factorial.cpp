#include<bits/stdc++.h>
using namespace std;
int factorial(int n){
    if(n <= 0) return 1; //base case is required for termination
    cout << "for calculating factorial of " << n << "\n";
    int ans = n * factorial(n - 1); // factorial is calling factorial that's why recursion.
    cout << "completed calculating factorial of " << n << " which is: " << ans << "\n";

    //recursion function completed.
    return ans;
}
int main(){
    int n;
    cin >> n;
    cout << factorial(n) << "\n";
    return 0;
}
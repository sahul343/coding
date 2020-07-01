#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < (1 << n); i ++){
        for(int j = 0; j < 32; j++){
            if(i & (1 << j)){
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    int x = 7;
    int b = 0;
    do{
        for(int i = 0; i < 32; i++){
            if( b & (1 << i)){
                cout << i;     
            }
        }
        cout << "\n";
    }while(b = (b - x) & x);
    return 0;
}
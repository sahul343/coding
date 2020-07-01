#include<bits/stdc++.h>
using namespace std;
const int maxn = 50;
int C[maxn + 1][maxn + 1];
//int C[maxn + 1][maxn + 1];
void coefficients(){
    C[0][0] = 1;
    for (int n = 1; n <= maxn; ++n) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k)
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
    }
}
int main(){
    int t;
    cin >> t;
    coefficients();
    for(int i = 1; i <= t; i++){
        int n;
        cin >> n;
        cout << "Case #"<<i<<":\n";
        if(n == 1){
            cout <<"1 1\n";
        }
        else{
            int x = 0, y = 0;
            for(int k = 0; k < 30; k++){
                if(n >= (1 << k)){
                    for(int j = 0; j <= k; j++){
                        if(k%2 == 1)
                            cout << (k + 1) << " " << (j + 1) << "\n";
                        else{
                            cout << (k + 1) << " " << (k + 1 - j) << "\n";
                        }
                    }
                    n = n - (1 << k);
                }
                else{
                    x = k; y = 0;
                    while(n){
                        if(n == C[x][1]){
                            if(k % 2 == 1)
                            cout << (x + 1) << " 2\n";
                            else{
                                cout << (x + 1) << " " << x << "\n";
                            }
                            n = 0;
                        }
                        else if(n > C[x][1]){
                            if(k%2 == 1){
                                cout << (x + 1) << " 2\n";
                                cout << (x + 1) << " 1\n";
                            }
                            else{
                                cout << (x + 1) << " " << x << "\n";
                                cout << (x + 1) << " " << (x + 1) << "\n";
                            }
                            n -= C[x][1] + 1;
                        }
                        else{
                            if(k%2 == 1)
                            cout << (x + 1) << " 1\n";
                            else{
                                cout << (x + 1) << " " << (x + 1) << "\n";
                            }
                            n --;
                        }
                        x ++;
                    }
                    break;
                }
                if(n < 0) break;
            }
        }
    }
    return 0;
}
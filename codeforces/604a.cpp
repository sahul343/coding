#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n+1];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        a[n] = a[n-1] + 1;
        n;
        int i = 0;
        vector<int>fre;
        int f = 1;
        while(i < n){
            if( a[i] == a[i+1]){
                f++;
            }
            else{
                fre.push_back(f);
                f = 1;
            }
            i++;
            //cout << i <<endl;
        }
        int n1 = fre.size();
        if(n1 < 3){
            cout << "0 0 0"<<endl;
        }
        else {
            i = 3;
            int g = fre[0], s = fre[1], b = fre[2];
            n1 = fre.size();
            // cout << "initially " << endl;
            // cout << g << " " << s << " " << b << endl;
            while(i< n1){  
                // cout << "while 2 " << i << endl;
                // cout << n1 << endl;
                // int x ;
                //scanf("%d",&x);
                if(g >= s){
                    s += b;
                    b = fre[i];
                }
                else if(g >= b){
                    b += fre[i];
                }
                else if(g+s+b+fre[i] <= n/2){
                    b += fre[i];
                }
                else{
                    break;
                }
                // cout << fre[i] << endl;
                // cout << g << endl;
                // cout << s << endl;
                // cout << b << endl;
                i++;
            }
            if(g < s && g < b && (g+s+b) <= n/2){
                cout << g << " " << s << " " << b << endl;
            }
            else{
                cout <<"0 0 0"<<endl;
            }
        }
    }
    return 0;
}
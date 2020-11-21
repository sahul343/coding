#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int mn = INT_MAX;
        map<int,int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            mn = min(mn, x);
            A[x]++;
        }
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            mn = min(mn, x);
            A[x]--;
        }
        bool possible = true;
        for(auto it=A.begin(); it!=A.end(); it++){
            if((it->second)%2 != 0){
                possible = false;
                break;
            }
            A[it->first] = (it->second)/2;
        }
        
        if(!possible){
            cout<<-1<<endl;
            continue;
        }

        vector<int> F1;
        vector<int> F2;

        for(auto it=A.begin(); it!=A.end(); it++){
            if(it->second > 0){
                for(int i=0;i<it->second;i++){
                    F1.push_back(it->first);
                }
            }
            else if(it->second < 0){
                for(int i=0;i<abs(it->second);i++){
                    F2.push_back(it->first);
                }
            }
        }

        int x = F1.size();
        if(x != F2.size()){
            cout<<-1<<endl;
            continue;
        }
        int y = 0;
        int i=0;
        int j=0;
        int ans = 0;
        while(y!=x){
            int nowmin = min(F1[i], F2[j]);
            if(nowmin > 2 * mn){
                ans += 2 * mn;
                y ++;
                continue;
            }
            if(F1[i] < F2[j]){
                ans+= F1[i];
                i++;
            }
            else{
                ans+= F2[j];
                j++;
            }
            y++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
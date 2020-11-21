#include<bits/stdc++.h>
using namespace std;
vector<int>arr;
bool compare(pair<int,int>& a, pair<int,int>&b){
    if(a.first == b.first) return arr[a.second] < arr[b.second];
    return a.first > b.first;
}
int mygcd(int a, int b){
    if(a < b) swap(a, b);
    while(b){
        int temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}
int main(){
    int t;
    cin >> t;
    while(t -- ){
        int n;
        cin >> n;
        arr.resize(n);
        for(int i = 0; i < n ; i ++){
            cin >> arr[i];
        }
        vector<pair<int,int> >b(n);
        for(int i = 0; i < n; i ++){
            b[i] = {arr[i], i};
        }
        int g = 1;
        for(int i = 0; i < n; i ++){
            sort(b.begin() + i, b.end(), compare);
            cout << arr[b[i].second] << " ";
            //g = mygcd(g, arr[b[i].second]);
            for(int j = i + 1; j < n; j ++){
                b[j].first = mygcd(arr[b[i].second], b[j].first);
            }
        }
        cout << "\n";
    }
    return 0;
}
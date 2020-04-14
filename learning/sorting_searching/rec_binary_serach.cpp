#include<bits/stdc++.h>
using namespace std;
int bin_search(int *a, int l, int r, int value){
    if(r < l) return -1;
    else if(l == r){
        if(a[l] == value) return l;
        else return -1;
    }
    int mid = l + (r - l)/2;
    if(a[mid] == value) return mid;
    else if(a[mid] < value) return bin_search(a, mid + 1, r, value);
    else return bin_search(a, l, mid - 1, value);
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << "Enter the value of index you want get\n";
    int value ;
    cin >> value;
    sort(a, a + n);
    if(bin_search(a, 0, n - 1, value) == -1){
        cout << "It's not there\n";
    }
    else{
        cout << bin_search(a, 0, n - 1, value) << "\n";
    }
    return 0;
}
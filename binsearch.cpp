#include<bits/stdc++.h>
using namespace std;
bool search(int* a, int low, int high, int x){
    if(low > high) return false;
    else if(low == high) return a[low] == x;
    else {
        int mid = (low + high)/2;
        if(a[mid] == x) return true;
        else if(a[mid] > x) return search(a, low, mid - 1, x);
        else return search(a, mid + 1, high, x);
    }
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    sort(a, a + n);  // used for sorting array
    int x;
    cout << "which number you want to search in the array: ";
    cin >> x;
    bool flag = search(a, 0, n - 1, x);
    if(flag) cout << "Yes it's present\n";
    else cout << "It's not present. oops\n";
    return 0;
}
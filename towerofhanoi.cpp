#include<bits/stdc++.h>
using namespace std;
void towerofhanoi(int n, string source, string temp, string dest){
    if(n <= 0) return; // 0 or less than 0 doesn't make sense
    else if(n == 1){
        cout << "Transferring disk from " << source << " to " << dest << "\n";
    }
    else {
        //we have to transfer n disks from source to destination.

        //tranfer n - 1 disks from source to temp using destination.
        towerofhanoi(n - 1, source, dest, temp); 

        //tranfer nth disk from source to destination.
        cout << "Transferring disk from " << source << " to " << dest << "\n";

        //tranfer n - 1 disks form temp to destination using source.
        towerofhanoi(n - 1, temp, source, dest);
    }
}
int main(){
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    string a = "t1", b = "t2", c = "t3";
    towerofhanoi(n, a, b, c);
    return 0;
}
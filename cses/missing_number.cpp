#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, curr;
    scanf("%d", &n);
    long sum = 0;
    for(int i = 0; i < n - 1; i ++){
        scanf("%d", &curr);
        sum += (i + 1 - curr);
    }
    sum += n;
    printf("%ld\n", sum);
}
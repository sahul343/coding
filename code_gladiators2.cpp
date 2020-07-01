/* Read input from STDIN. Print your output to STDOUT*/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#define ll long long
void merge(ll *a, int l, int mid, int r){
    int n1 = (mid - l) + 1;
    int n2 = (r - mid);
    ll b[n1];
    ll c[n2];
    for(int i = 0; i < n1; i++){
        b[i] = a[l + i];
    }
    for(int i = 0; i < n2; i++){
        c[i] = a[mid  + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while( i < n1 && j < n2){
        if(b[i] < c[j]){
            a[k] = b[i];
            i ++;
        }
        else{
            a[k] = c[j];
            j ++;
        }
        k ++;
    }
    while(i < n1){
        a[k] = b[i];
        i ++;
        k ++;
    }
    while(j < n2){
        a[k] = c[j];
        k ++;
        j ++;
    }
}
void merge_sort(ll *a, int l, int r){
    if(l < r){
        int mid = l + (r - l)/2;
        merge_sort(a, l, mid );
        merge_sort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}
int main(int argc, char *a[])
{
    int t;
    scanf("%d", &t);
    while( t --){
        int n;
        scanf("%d", &n);
        ll a[n], b[n];
        for(int i = 0; i < n; i++){
            scanf("%lld", &a[i]);
        }
        for(int i = 0; i < n; i++){
            scanf("%lld", &b[i]);
        }
        merge_sort(a, 0, n - 1);
        merge_sort(b, 0, n - 1);
        int i = 0, j = 0;
        int ans = 0;
        while(i < n && j < n){
            if(a[i] > b[j]){
                ans ++;
                j ++;
            }
            i ++;
        }
        printf("%d\n", ans);
    }
}

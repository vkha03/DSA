#include<stdio.h>
void quicksort(int arr[], int left, int right){
    int l = left, r = right, m = arr[(left + right)/2];
    do{
        while(arr[l] < m) l++;
        while(arr[r] > m) r--;
        if(l<=r){
            int tmp = arr[l];
            arr[l] = arr[r];
            arr[r] = tmp;
            l++;
            r--;
        }
    } while(l <= r);
    if(left<r) quicksort(arr, left, r);
    if(right>l) quicksort(arr, l, right);
}
int main(){
int arr[] = {9,10,8,8,6,7,9,20};
quicksort(arr, 0, 7);
for(int i = 0; i < 8; i++){
    printf("%d",arr[i]);
}
}

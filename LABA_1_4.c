#include <stdlib.h>
#include <stdio.h>

void mobilizatsia(int arr1[], int arr2[], int len){
    int *a1p0 = arr1; //указатель на первый элемент первого массива
    int *a2p0 = arr2; //указатель на второй элемент второго массива

    int courier;

    for (int i = 0; i < len; ++i){

        int *cur_el1 = a1p0 + i;

        courier = *cur_el1;

        int *cur_el2 = a2p0 + i;

        *cur_el2 = courier;
    }
}
// ONO RABOTAET???
int main(){
    int arr1[] = {2, 2, 3, 5, 5};
    int arr2[5];
    int len = 5;
    mobilizatsia(arr1, arr2, len);
    
    for (int i = 0; i < len; ++i){
        printf("%d\n", arr2[i]);
    }
    return 0;
}
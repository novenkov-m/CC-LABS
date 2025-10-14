#include <stdlib.h>
#include <stdio.h>

void mobilizatsia(int arr1[], int arr2[], int len){
    if (arr1 == NULL || arr2 == NULL || len <= 0) {return;}
        
    int *a1p0 = arr1; //указатель на первый элемент первого массива
    int *a2p0 = arr2; //указатель на второй элемент второго массива

    for (int i = 0; i < len; ++i){

        int *cur_el1 = a1p0 + i;
        int *cur_el2 = a2p0 + i;
        
        *cur_el2 = *cur_el1;
        
    }
}
// ONO RABOTAET???
int main(){
    int len = 5;
    int arr1[] = {1, 5, 6, 1, 4}; // dlina - len
    int *arr2 = (int *)malloc(sizeof(int)*len);
    
    printf("Perviy massiv\n");
    for (int i = 0; i < len; ++i)
        printf("%d ", arr1[i]);
    
    printf("\n");

    mobilizatsia(arr1, arr2, len);
    // vivod
    printf("Vtoroy massiv\n");
    for (int i = 0; i < len; ++i)
        printf("%d ", arr2[i]);
    printf("\n");
    free(arr2);
    return 0;
}

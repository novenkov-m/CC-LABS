#include <stdio.h>
#include <stdlib.h>

// p0 - указатель на первый элемент подмассива


int chasteish(int arr[], int len, int left_border){
    
    if (arr == NULL || left_border < 0 || left_border >= len) {
        return -1; // Возвращаем -1 в случае ошибки
    }

    int *p0 = arr + left_border;
    int *p00 = p0;
    int most_fr = *p00;
    int max_count = 0;
    int len_b = len - left_border;
    int cur_count;

    for (int i = 0; i < (len_b-1); ++i){
        
        int *cur_el = p0 + i;
        cur_count = 0;


        for (int j = 0; j < len_b-1; ++j){

            int *p1 = p0 + j;
            int *cur_el1 = cur_el;

            if (*p1 == *cur_el1) {++cur_count;}

        }

        if (cur_count > max_count){
            max_count = cur_count;
            most_fr = *cur_el;
        }
    }

    int end = *p0;

    return most_fr;
    
}
// PROVERKA 
int main(){
    int len = 8;
    int left_border;
    scanf("%d", &left_border);
    int a[] = {5, 5, 5, 5, 5, 3, 3,3};
    printf("%d\n", chasteish(a, 8, left_border));
    return 0;
}
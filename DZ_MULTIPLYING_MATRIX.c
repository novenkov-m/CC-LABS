#include <stdio.h>
#include <stdlib.h>

/*Дз до 17.10.25 23:59:
Написать функцию, которая принимает на вход:
MatrixA, MatrixB, output, N, M, K
И производит перемножение матрицы A на матрицу B,
складывая результат в output */


// заполняем матрицу чиселками одной длины (чтоб красивей смотрелось)
void fill_mat(float** arr, int m, int n){
    for (int i = 0; i<m; ++i){
        for (int j = 0; j < n; ++j){
            arr[i][j] = 10 + rand()%90 + (float)rand()/(float)RAND_MAX; // случайное двузначное число
        }
    }
}
// возвращаем память этой консервной банке
void clear_mem(float** matrix, int strochki){
    for (int i = 0; i < strochki; ++i)   free(matrix[i]);
    free(matrix);
}


// peremnozhenie
void multimatritsa(
    float** matrixA,
    float** matrixB,
    float** output,
    int m, int n, int k){
        for (int i = 0; i < m; ++i){ // строки матрицы А
            for (int j = 0; j < k; ++j){ // столбцы матрицы B
                float cur_el = 0;

                for (int h = 0; h < n; ++h){
                    cur_el += matrixA[i][h]*matrixB[h][j];
                }
                output[i][j] = cur_el;
            }
        }
    }

//vivod
void print_mat(float** arr, int m, int n){

    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j) printf("%.2f ", arr[i][j]);
        printf("\n");
    }
    
        
}

int main(){

    int m = 5; int n = 4; int k = 3;

    float **matrixA = (float**)malloc(sizeof(float*)*m);
    for (int i = 0; i < m; ++i){
        matrixA[i] = (float*)malloc(sizeof(float)*n);
    }

    float **matrixB = (float**)malloc(sizeof(float*)*n);
    for (int i = 0; i < n; ++i){
        matrixB[i] = (float*)malloc(sizeof(float)*k);
    }

    float **output = (float**)malloc(sizeof(float*)*m);
    for (int i = 0; i < m; ++i){
        output[i] = (float*)malloc(sizeof(float)*k);
    }

    fill_mat(matrixA, m, n);
    fill_mat(matrixB, n, k);

    // peremnozhenie)
    multimatritsa(matrixA, matrixB,output,m, n, k);
    
    printf("\n##      RANDOM NUMS; M=5 N=4 K=3     ##\n\n");
    print_mat(matrixA, m, n);
    printf("\n");
    print_mat(matrixB, n, k);
    printf("\n");
    print_mat(output, m, k);
    printf("\n###TEST 2 (OBRATNIE MATRITSI)#########\n");


    // возвращаем память консервной банке 
    clear_mem(matrixA, m);
    clear_mem(matrixB, n);
    clear_mem(output, m);

    // TEST 2 (s obratnimi matritsami)

    float **matrixA2 = (float**)malloc(sizeof(float*)*3);
    for (int i = 0; i < 3; ++i){
        matrixA2[i] = (float*)malloc(sizeof(float)*3);
    }

    float **matrixB2 = (float**)malloc(sizeof(float*)*3);
    for (int i = 0; i < 3; ++i){
        matrixB2[i] = (float*)malloc(sizeof(float)*3);
    }

    float **output2 = (float**)malloc(sizeof(float*)*3);
    for (int i = 0; i < 3; ++i){
        output2[i] = (float*)malloc(sizeof(float)*3);
    }
    
    // zapolnenie
    float arr1[] = {3, 5, -2, 1, -3, 2,6,7,-3};
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j)
            matrixA2[i][j] = arr1[i*3+j];
    };
    float arr2[] = {-0.5,0.1,0.4,1.5,0.3,-0.8,2.5,0.9,-1.4};
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j)
            matrixB2[i][j] = arr2[i*3+j];
    }
    // vivod 
    printf("\n");
    print_mat(matrixA2, 3, 3);
    printf("\n");
    print_mat(matrixB2, 3, 3);
    printf("\n");
    multimatritsa(matrixA2, matrixB2, output2, 3,3,3);

    print_mat(output2, 3, 3);




    clear_mem(matrixA2, 3);
    clear_mem(matrixB2, 3);
    clear_mem(output2, 3);
    return 0;
}
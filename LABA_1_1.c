#include <stdio.h>
#include <stdlib.h>

// ИЩУ МАКСИМУМ
int max_ferstappen(int array[], int len){
    int maxx = array[0];
    for (int i = 1; i<len; ++i){
        if (array[i] > maxx){
            maxx = array[i];
        }
    }
    return maxx;
}
// ИЩУ МИНИМУМ
int chi_min(int array[], int len){
    int minn = array[0];
    for (int i = 1; i<len; ++i){
        if (array[i] < minn){
            minn = array[i];
        }
    }
    return minn;
}
// ИЩУ СРЕДНЯК
float AVG(int array[], int len){
    int sum = 0;
    for (int i = 0; i < len; ++i){
        sum += array[i];
    };
    float avg =  sum/(float)len;
    return avg;
}

int main(){
    int n;
    scanf("%d", &n);
    srand(1); 
    int *p = (int*)malloc(n*sizeof(int));
    if (p == NULL) {
    printf("error");
    return 1;
    }

    for (int i=0; i<n; ++i){
        p[i] = rand()%16257;
    };
    printf(
        "Max %d; Min %d; Average %.2f\n",
         max_ferstappen(p, n),
         chi_min(p,n),
         AVG(p, n)
         
        );
        
    free(p);
    return 0;
}
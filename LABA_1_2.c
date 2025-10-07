#include <stdio.h>
#include <math.h>

struct Point {
    double x;
    double y;
};

// RASSTOYANIE
double calculateDistance(struct Point p1, struct Point p2){
    double distance = pow(
        pow((p1.x - p2.x), 2.0)
        + pow((p1.y - p2.y), 2.0),
        0.5
        );
    return distance;
}

// PLOSCHAD 
double calculateArea(struct Point p1, struct Point p2){
    double area = fabs((p1.x - p2.x) * (p1.y-p2.y) );
    return area;
}

//PROVERKA ETOY HALABUDY SVERHU
int main(){
    printf("Введи корды точек в формате x1 y1 x2 y2\n");
    double x1, y1, x2, y2;
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    struct Point p1;
    p1.x = x1; p1.y = y1;
    struct Point p2;
    p2.x = x2; p2.y = y2;

    printf(
        "%.2lf - ploschad\n",
        calculateArea(p1, p2)
    );

    return 0;
}
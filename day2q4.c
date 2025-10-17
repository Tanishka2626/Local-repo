// Write  program to calculate the area and circumference of a circle given its radius.
#include <stdio.h>
int main(){
    float r;
    printf("Enter radius: ");
    scanf("%f", &r);
    printf("Area = %.2f\nCircumference = %.2f\n", 3.14159*r*r, 2*3.14159*r);
    return 0;
}
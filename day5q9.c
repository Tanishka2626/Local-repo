//Write  program to calculate simple and compound interest for given principal, rate, and time.
#include <stdio.h>
#include <math.h>
int main(){
    float p, r, t;
    printf("Enter P, R, T: ");
    scanf("%f%f%f", &p, &r ,&t);
    printf("SI=%.2f\nCI=%.2f",
    (p*r*t)/100, p*pow(1+r/100,t)-p);
    return 0;
    

}
//Write program to find the roots of a quadratic equation and categorize them.
// IF D=0 (roots are real and equal), D>0 real and  distinct, D<0 imaginary
#include <stdio.h>
#include <math.h> // WE use this is a header file in C that gives us access to square root, power, sine, cosine etc
int main(){
    float a, b, c, d, r1, r2;
    printf("Enter a b c: ");
    scanf("%f %f %f", &a, &b, &c);
    d = b*b - 4*a*c; // d is discriminant
    if(d>0){
        r1 = (-b + sqrt(d))/(2*a);
        r2 = (-b - sqrt(d))/(2*a);
        printf("Real and distinct roots: %.2f, %.2f", r1, r2);
    }
    else if (d==0) {
        r1 = -b/(2*a);
        printf("Real and equal root: %.2f", r1);
    }
    else
        printf("Imaginary roots");
    return 0;    
}

//Write  program to classify a triangle as Equilateral, Isosceles, or Scalene based on its side lengths.
#include <stdio.h>
int main(){
    int a, b, c;
    printf("Enter three sides: ");
    scanf("%d %d %d", &a, &b ,&c);
    if(a==b && b==c)
    printf("Equilateral");
    else if(a==b || b==c || c==a)
    printf("Isosceles");
    else printf("Scalene");
    return 0;
}
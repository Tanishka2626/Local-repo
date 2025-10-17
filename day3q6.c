//Write  program to swap two numbers using a third variable.
#include <stdio.h>

int main(){
    int a, b, t;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    t = a; a = b; b =t ; // t = temporarily number
    printf("After swapping: %d %d\n", a, b);
    return 0;
}

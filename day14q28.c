// write program to print the product of even numbers from 1 to n
#include <stdio.h>
int main(){
    int n, prod = 1;
    scanf("%d", &n);
    for(int i = 2 ; i <= n; i += 2)
    prod *= i;
    printf("%d", prod);
}
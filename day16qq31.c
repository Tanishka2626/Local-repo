//Write  program to take a number as input and print its equivalent binary representation.
#include <stdio.h>
int main(){
    int n, bin = 0, base = 1;
    scanf("%d", &n);
    while(n > 0){
        bin += (n % 2) * base;
        n /= 2;
        base *= 10;
    }
    printf("%d", bin);
}
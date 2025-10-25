//Write  program to check if a number is an Armstrong number.
#include <stdio.h>
#include <math.h>
int main(){
    int n, temp, sum = 0, d;
    scanf("%d", &n);
    temp = n;
    while(temp > 0) {
        d = temp % 10;
        sum += d *d *d;
        temp /= 10;
    }
    printf(sum == n ? "Armstrong" :
    "Not Armstrong");

}
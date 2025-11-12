//Write  program to find the HCF (GCD) of two numbers
#include <stdio.h>
int main (){
    int num1, num2, gcd = 1, i;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
     
    i = 1;
    while(i <= num1 && i <= num2){
         if(num1 % i == 0 && num2 % i == 0)
         gcd = i;
         i++;
    }
    printf("HCF of %d and %d = %d", num1, num2, gcd);
    return 0;

}
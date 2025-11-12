//Write  program to find the product of odd digits of a number.
#include <stdio.h>
int main(){
    int num, digit , product = 1;
    printf("Enter a number: ");
    scanf("%d", &num);
    while(num != 0){
        digit = num % 10; // last digit
        if(digit %2 != 0) // check if the digit is odd
        product = product * digit; // multiply if odd
        num = num / 10; // removes the last digit 

        
    }
    printf("Product of odd digits = %d", product);// example - number = 345, 345%10 = 5 check if 5 is odd (yes) now 1x5=5; new num(/10)=34 ,34%10=4 check 4 is not odd so the product is still 5, 3x5=15 (ans)
    return 0;
}
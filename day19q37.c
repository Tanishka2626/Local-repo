//Write  program to find the LCM of two numbers.
#include <stdio.h>
int main(){
    int num1, num2, max;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // find the largest number bcz LCM can never be smaller than both numbers , the first number divisible by both will be the LCM
    max = ( num1 > num2) ? num1 : num2;
    // keep increasing max until it becomes divisible by both 
    while(1){             // while(1) means run the loop forever infinite loop and then we use break to exit the loop
        if(max % num1 == 0 && max % num2 == 0){
        printf("LCM of %d and %d = %d", num1, num2, max);
        break;
        } // if we have more than one line in if statement the use{}, to run the whole block
        max++;
    } 
    return 0;
}
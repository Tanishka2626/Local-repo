//Write  program to find the sum of digits of a number.
#include <stdio.h>
int main(){
    int num , sum = 0, digit;
    printf("Enter a number: ");
    scanf("%d", &num);

    while(num != 0){
        digit = num % 10;  // get the last digit
        sum  = sum + digit; // add it to sum
        num = num /10 ; // when you divide an integer by 10 in C, it drops the decimal part. ex- 345 / 10= 34.5 = 34
}
    printf("sum of digits = %d", sum);
return 0;

}
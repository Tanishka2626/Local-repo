//Write a program to input a year and check whether it is a leap year or not using conditional statements 
// LEAP year is divisible by 4 but not by 100 or divisible by 400
# include <stdio.h>
int main(){
    int y;
    printf("Enter year: ");
    scanf("%d", &y);
    if((y%4==0 && y%100!=0 || y%400==0))
    printf("Leap year");
    else
        printf("Not a leap year");
    return 0;    
}
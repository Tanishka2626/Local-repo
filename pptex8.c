//enter the marks of students
#include <stdio.h>

void main(){
    int marks[10],i,n,sum =0; // marks[10]can enter marks of 10 students, i= loop counter, n= number of students entered by user,sum =0 variable to store total of all marks
    printf("Enter number of students:");
    scanf("%d",&n);
    for( i =0; i<n; i++)
{
    printf("Enter marks of student%d:\n",i+1); // i+1 because array starts from 0 but students starts from 1
    scanf("%d",&marks[i]);
    sum+=marks[i]; // adds the entered marks into the running total(sum)

}
printf("Sum= %d",sum); // after the loop finishes prints the total sum of marks of all students
return 0;
}
   
// Write a program to calculate the area and perimeter of rectangle given its length and breadth
#include <stdio.h>

int main(){
    float length, breadth, area, perimeter;
    // input length and breadth
    printf("Enter the length of the rectangle: ");
    scanf("%f", &length);

    printf("Enter the breadth of the rectangle: ");
    scanf("%f", &breadth);

    // calculate the area and perimeter
    area = length * breadth;
    perimeter = 2 * (length + breadth);
    // display results
    printf("Area of the reactangle = %.2f\n",area);
    printf("Perimeter of the rectangle = %.2f\n", perimeter);

    return 0;
}
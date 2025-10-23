//Write  program to input time in seconds and convert it to hours:minutes:seconds format.
#include <stdio.h>
int main(){
    int s;
    printf("Enter seconds: ");
    scanf("%d", &s);
    printf("%02d:%02d:%02d", s/3600, (s%3600)/60, s%60); //%02d- prints each value in two digits ( 01:05:09)
    return 0;
}

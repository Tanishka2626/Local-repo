// Write  program to print all the prime numbers from 1 to n.
#include <stdio.h>
int main() {
    int num, div, limit, flag;
    printf("Enter limit: ");
    scanf("%d", &limit);

    for(num = 2; num <= limit; num++) {
        flag = 1;
        for(div = 2; div <= num/2; div++) {
            if(num % div == 0) {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
            printf("%d ", num);
    }
    return 0;
}

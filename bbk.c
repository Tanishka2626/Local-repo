#include <stdio.h>

int main(){
    int a = 10;
    printf("Outside all inner blocks: a = %d\n", a);
    {
        int b = 20;
        printf("Inside Block 1: a = %d, b = %d\n", a, b);

    }
    {
        int c = 30;
        a = a + c;
        printf("Inside Block 2: a = %d, c = %d\n", a,c);

    }
    printf("Back in main after blocks: a = %d\n",a);
    return 0;
}
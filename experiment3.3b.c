#include <stdio.h>

int main (){
    int n = 5;
    for (int i = 1; i<= n; i++){
        // print spaces
        for (int space = 1; space <= n
        -i; space++) {
            printf(" ");
        }
        // print increasing numbers
        for (int j =1; j <= i; j++){
            printf("%d", j);
        }
        // print decreasing numbers
        for (int j = i-1; j >= 1;
        j--){
            printf("%d", j);
        }
        printf("\n");
    }
    return 0;
}
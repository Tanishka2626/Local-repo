//Write  program to check if a number is a palindrome.
#include <stdio.h>
int main(){
    int n, rev = 0, temp;
    scanf("%d", &n);
    temp = n;
    while(n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    printf(temp == rev?
    "Palindrome" : "Not Palindrome");
}
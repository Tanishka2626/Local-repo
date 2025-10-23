//Write  program to input a character and check whether it is an uppercase alphabet, lowercase alphabet, digit, or special character.
#include <stdio.h>
int main(){
    char c;
    printf("Enter a character: ");
    scanf("%c", &c);
    if(c>='A' && c<='Z')
    printf("Uppercase");
    else if(c>='a' && c<='z')
    printf("Lower case");
    else if(c>='0' && c<='9')
    printf("Digit");
    else printf("Special character");
    return 0;
}
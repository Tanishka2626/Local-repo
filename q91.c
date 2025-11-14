#include <stdio.h>

int main() {
    char txt[100], final[100];
    int a, b = 0;

    printf("Enter a string: ");
    fgets(txt, sizeof(txt), stdin);

    // removing vowels
    for(a = 0; txt[a] != '\0'; a++) {
        // checking if current character is NOT a vowel
        if(txt[a]!='a' && txt[a]!='e' && txt[a]!='i' && txt[a]!='o' && txt[a]!='u' &&
           txt[a]!='A' && txt[a]!='E' && txt[a]!='I' && txt[a]!='O' && txt[a]!='U') 
        {
            final[b] = txt[a]; 
            b++;   
        }
    }

    final[b] = '\0';  // ending the new string

    printf("String without vowels: %s", final);

    return 0;
}

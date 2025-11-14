#include <stdio.h>

int main() {
    char text[100];
    int used[26] = {0};  // to store count of each lowercase letter
    int p, index, found = 0;

    printf("Enter a string: ");
    fgets(text, sizeof(text), stdin);

    // checking characters one by one
    for(p = 0; text[p] != '\0'; p++) {
        
        // only check lowercase a-z
        if(text[p] >= 'a' && text[p] <= 'z') {
            index = text[p] - 'a';  // convert char to index 0-25
            
            if(used[index] == 1) {  
                // if already seen → it's the FIRST repeating lowercase
                printf("First repeating lowercase alphabet: %c\n", text[p]);
                found = 1;
                break;
            }
            else {
                used[index] = 1;  // mark as seen
            }
        }
    }

    if(found == 0) {
        printf("No repeating lowercase alphabet found.\n");
    }

    return 0;
}

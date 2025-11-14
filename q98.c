#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    int i, lastPos = -1;

    printf("Enter your full name: ");
    fgets(name, sizeof(name), stdin);

    // Find last space → where surname starts
    for(i = 0; name[i] != '\0'; i++) {
        if(name[i] == ' ')
            lastPos = i;
    }

    // Print initials from start to last name start
    if(name[0] != ' ')
        printf("%c ", name[0]);

    for(i = 0; name[i] != '\0'; i++) {
        if(name[i] == ' ' && i < lastPos && name[i+1] != ' ')
            printf("%c ", name[i+1]);
    }

    // Print surname in full
    printf("%s", &name[lastPos + 1]);

    return 0;
}

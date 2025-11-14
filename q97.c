#include <stdio.h>
#include <string.h>

int main() {
    char full[100];
    int i;

    printf("Enter your name: ");
    fgets(full, sizeof(full), stdin);

    // First character is always an initial (if not space)
    if(full[0] != ' ')
        printf("%c", full[0]);

    // Whenever a space appears, print next character as initial
    for(i = 0; full[i] != '\0'; i++) {
        if(full[i] == ' ' && full[i+1] != ' ' && full[i+1] != '\0') {
            printf("%c", full[i+1]);
        }
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    char d[12], final[20];

    printf("Enter date (dd/04/yyyy): ");
    fgets(d, sizeof(d), stdin);

    // Copy first two digits (day)
    final[0] = d[0];
    final[1] = d[1];
    final[2] = '-';

    // Add fixed month "Apr"
    final[3] = 'A';
    final[4] = 'p';
    final[5] = 'r';
    final[6] = '-';

    // Copy last 4 digits (year)
    final[7]  = d[6];
    final[8]  = d[7];
    final[9]  = d[8];
    final[10] = d[9];
    final[11] = '\0';      // end string

    printf("Formatted date: %s\n", final);
    return 0;
}

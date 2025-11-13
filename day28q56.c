// Read  print elements of a one-dimensional array.
#include <stdio.h>
int main() {
    int box[20], total, z;
    printf("Enter total elements: ");
    scanf("%d", &total);

    for(z = 0; z < total; z++) {
        printf("Enter value %d: ", z + 1);
        scanf("%d", &box[z]);
    }

    printf("Array elements are: ");
    for(z = 0; z < total; z++)
        printf("%d ", box[z]);
    return 0;
}

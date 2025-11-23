#include <stdio.h>
#include <string.h>

#define MAX 10

// Structure for delivery points
struct DeliveryPoint {
    char name[30];
    float distance;   // in km
    int priority;     // 1 = High, 2 = Medium, 3 = Low
    float weight;     // in kg
};

// Function declarations
void inputData(struct DeliveryPoint dp[], int *n);
void displayData(struct DeliveryPoint dp[], int n);
int findNearest(struct DeliveryPoint dp[], int n);
void sortByDistance(struct DeliveryPoint dp[], int n);
void sortByPriority(struct DeliveryPoint dp[], int n);
float totalBattery(struct DeliveryPoint dp[], int n);
void optimizedRoute(struct DeliveryPoint dp[], int n);

int main() {
    struct DeliveryPoint dp[MAX];
    int n = 0;           // initialize n to 0 to avoid using garbage
    int choice;

    while (1) {
        printf("\n==== Drone Delivery Route Optimizer ====\n");
        printf("1. Enter Delivery Points\n");
        printf("2. Display Delivery Points\n");
        printf("3. Find Nearest Delivery Point\n");
        printf("4. Sort by Distance (Shortest First)\n");
        printf("5. Sort by Priority (High → Low)\n");
        printf("6. Calculate Total Battery Required\n");
        printf("7. Show Optimized Route\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            // clear invalid input
            int c; while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid input. Please enter a number between 1 and 8.\n");
            continue;
        }

        switch (choice) {
        case 1:
            inputData(dp, &n);
            break;

        case 2:
            if (n <= 0) {
                printf("No delivery points entered yet. Choose option 1 first.\n");
            } else {
                displayData(dp, n);
            }
            break;

        case 3:
            if (n <= 0) {
                printf("No delivery points entered yet. Choose option 1 first.\n");
            } else {
                {
                    int idx = findNearest(dp, n);
                    printf("\nNearest Delivery Point: %s (%.2f km)\n",
                           dp[idx].name, dp[idx].distance);
                }
            }
            break;

        case 4:
            if (n <= 0) {
                printf("No delivery points entered yet. Choose option 1 first.\n");
            } else {
                sortByDistance(dp, n);
                printf("\nSorted by Distance.\n");
            }
            break;

        case 5:
            if (n <= 0) {
                printf("No delivery points entered yet. Choose option 1 first.\n");
            } else {
                sortByPriority(dp, n);
                printf("\nSorted by Priority.\n");
            }
            break;

        case 6:
            if (n <= 0) {
                printf("No delivery points entered yet. Choose option 1 first.\n");
            } else {
                printf("\nTotal Battery Required: %.2f units\n", totalBattery(dp, n));
            }
            break;

        case 7:
            if (n <= 0) {
                printf("No delivery points entered yet. Choose option 1 first.\n");
            } else {
                optimizedRoute(dp, n);
            }
            break;

        case 8:
            printf("Exiting.\n");
            return 0;

        default:
            printf("\nInvalid Choice! Enter 1-8.\n");
        }
    }
}


// Function to input data
void inputData(struct DeliveryPoint dp[], int *n) {
    int temp;
    printf("\nEnter number of Delivery Points (max %d): ", MAX);
    if (scanf("%d", &temp) != 1) {
        int c; while ((c = getchar()) != '\n' && c != EOF);
        printf("Invalid number.\n");
        *n = 0;
        return;
    }

    if (temp < 1 || temp > MAX) {
        printf("Number must be between 1 and %d.\n", MAX);
        *n = 0;
        return;
    }
    *n = temp;

    for (int i = 0; i < *n; i++) {
        printf("\n--- Delivery Point %d ---\n", i + 1);

        // read name safely
        printf("Enter Name: ");
        if (scanf("%29s", dp[i].name) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF);
            dp[i].name[0] = '\0';
        }

        printf("Enter Distance from Base (km): ");
        while (scanf("%f", &dp[i].distance) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid. Enter numeric distance: ");
        }

        printf("Enter Priority (1=High, 2=Medium, 3=Low): ");
        while (scanf("%d", &dp[i].priority) != 1 || dp[i].priority < 1 || dp[i].priority > 3) {
            int c; while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid. Enter 1, 2 or 3: ");
        }

        printf("Enter Weight of Package (kg): ");
        while (scanf("%f", &dp[i].weight) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid. Enter numeric weight: ");
        }
    }
}


// Display data
void displayData(struct DeliveryPoint dp[], int n) {
    printf("\n%-15s %-10s %-10s %-10s\n", "Name", "Distance", "Priority", "Weight");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-15s %-10.2f %-10d %-10.2f\n",
               dp[i].name, dp[i].distance, dp[i].priority, dp[i].weight);
    }
}


// Find nearest location
int findNearest(struct DeliveryPoint dp[], int n) {
    int minIndex = 0;

    for (int i = 1; i < n; i++) {
        if (dp[i].distance < dp[minIndex].distance) {
            minIndex = i;
        }
    }
    return minIndex;
}


// Sort by distance (Bubble Sort)
void sortByDistance(struct DeliveryPoint dp[], int n) {
    struct DeliveryPoint temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (dp[j].distance > dp[j + 1].distance) {
                temp = dp[j];
                dp[j] = dp[j + 1];
                dp[j + 1] = temp;
            }
        }
    }
}


// Sort by priority (1 → 2 → 3)
void sortByPriority(struct DeliveryPoint dp[], int n) {
    struct DeliveryPoint temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (dp[j].priority > dp[j + 1].priority) {
                temp = dp[j];
                dp[j] = dp[j + 1];
                dp[j + 1] = temp;
            }
        }
    }
}


// Calculate total battery
float totalBattery(struct DeliveryPoint dp[], int n) {
    float total = 0;

    for (int i = 0; i < n; i++) {
        total += dp[i].distance * (1 + dp[i].weight / 10.0f);
    }
    return total;
}


// Optimized route (after sorting by distance)
void optimizedRoute(struct DeliveryPoint dp[], int n) {
    sortByDistance(dp, n);

    printf("\nOptimized Route (Shortest First):\n");
    printf("Base");
    for (int i = 0; i < n; i++) {
        printf(" -> %s", dp[i].name);
    }
    printf(" -> End\n");
}

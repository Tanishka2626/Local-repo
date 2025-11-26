#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For exit() if needed, but not strictly used here

#define MAX_POINTS 10
#define NAME_LENGTH 30

// Structure for delivery points
struct DeliveryPoint {
    char name[NAME_LENGTH];
    float distance;   // Distance from base (one-way, in km)
    int priority;     // 1 = High, 2 = Medium, 3 = Low
    float weight;     // Package weight (in kg)
};

// Function declarations
void inputData(struct DeliveryPoint dp[], int *n);
void displayData(struct DeliveryPoint dp[], int n);
int findNearest(struct DeliveryPoint dp[], int n);
void sortByDistance(struct DeliveryPoint dp[], int n);
void sortByPriority(struct DeliveryPoint dp[], int n);
float totalBatteryRequired(struct DeliveryPoint dp[], int n);
void optimizedRoute(struct DeliveryPoint dp[], int n);
void clear_input_buffer(); // Helper function for robust input

int main() {
    struct DeliveryPoint dp[MAX_POINTS];
    int n = 0;              // Number of points entered
    int choice;

    while (1) {
        printf("\n==== 🚁 Drone Delivery Route Optimizer ====\n");
        printf("1. Enter Delivery Points\n");
        printf("2. Display Delivery Points\n");
        printf("3. Find Nearest Delivery Point\n");
        printf("4. Sort by Distance (Shortest First)\n");
        printf("5. Sort by Priority (High -> Low)\n");
        printf("6. Calculate Total Battery Required\n");
        printf("7. Show Simple Optimized Route (Distance-based)\n");
        printf("8. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            clear_input_buffer();
            printf("\n\t*** Invalid input. Please enter a number (1-8). ***\n");
            continue;
        }

        switch (choice) {
            case 1:
                inputData(dp, &n);
                break;

            case 2:
                if (n <= 0) {
                    printf("\n\t*** No delivery points entered yet. ***\n");
                } else {
                    displayData(dp, n);
                }
                break;

            case 3:
                if (n <= 0) {
                    printf("\n\t*** No delivery points entered yet. ***\n");
                } else {
                    int idx = findNearest(dp, n);
                    printf("\nClosest Delivery Point: **%s** (%.2f km from Base)\n",
                           dp[idx].name, dp[idx].distance);
                }
                break;

            case 4:
                if (n <= 0) {
                    printf("\n\t*** No delivery points entered yet. ***\n");
                } else {
                    sortByDistance(dp, n);
                    printf("\nData Sorted by **Distance** (Shortest First).\n");
                    displayData(dp, n);
                }
                break;

            case 5:
                if (n <= 0) {
                    printf("\n\t*** No delivery points entered yet. ***\n");
                } else {
                    sortByPriority(dp, n);
                    printf("\nData Sorted by **Priority** (High -> Low).\n");
                    displayData(dp, n);
                }
                break;

            case 6:
                if (n <= 0) {
                    printf("\n\t*** No delivery points entered yet. ***\n");
                } else {
                    printf("\nEstimated Total Battery Required (including return): **%.2f units**\n",
                           totalBatteryRequired(dp, n));
                }
                break;

            case 7:
                if (n <= 0) {
                    printf("\n\t*** No delivery points entered yet. ***\n");
                } else {
                    optimizedRoute(dp, n);
                }
                break;

            case 8:
                printf("\nExiting Drone Delivery Optimizer. Goodbye!\n");
                return 0;

            default:
                printf("\n\t*** Invalid Choice! Please enter a number between 1 and 8. ***\n");
        }
    }
}

// Clears the input buffer to prevent common scanf issues
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to input data
void inputData(struct DeliveryPoint dp[], int *n) {
    int temp_n;
    printf("\nEnter number of Delivery Points (max %d): ", MAX_POINTS);

    if (scanf("%d", &temp_n) != 1) {
        clear_input_buffer();
        printf("\n*** Invalid number entered. Returning to menu. ***\n");
        return;
    }
    clear_input_buffer(); // Clear buffer after number input

    if (temp_n < 1 || temp_n > MAX_POINTS) {
        printf("\n*** Number must be between 1 and %d. ***\n", MAX_POINTS);
        return;
    }
    *n = temp_n;

    for (int i = 0; i < *n; i++) {
        printf("\n--- Delivery Point %d ---\n", i + 1);

        // Read name safely
        printf("Enter Name (max %d chars): ", NAME_LENGTH - 1);
        if (fgets(dp[i].name, NAME_LENGTH, stdin) == NULL) {
             dp[i].name[0] = '\0'; // Handle error
        } else {
            // Remove the newline character added by fgets
            dp[i].name[strcspn(dp[i].name, "\n")] = 0;
        }

        printf("Enter Distance from Base (km): ");
        while (scanf("%f", &dp[i].distance) != 1 || dp[i].distance < 0) {
            clear_input_buffer();
            printf("*** Invalid. Enter positive numeric distance (km): ");
        }

        printf("Enter Priority (1=High, 2=Medium, 3=Low): ");
        while (scanf("%d", &dp[i].priority) != 1 || dp[i].priority < 1 || dp[i].priority > 3) {
            clear_input_buffer();
            printf("*** Invalid. Enter 1, 2 or 3: ");
        }

        printf("Enter Weight of Package (kg): ");
        while (scanf("%f", &dp[i].weight) != 1 || dp[i].weight < 0) {
            clear_input_buffer();
            printf("*** Invalid. Enter positive numeric weight (kg): ");
        }
        clear_input_buffer(); // Clear buffer after final input
    }
}

// Display data
void displayData(struct DeliveryPoint dp[], int n) {
    printf("\n## Delivery Points List ##\n");
    printf("%-20s %-12s %-10s %-10s\n", "Name", "Distance (km)", "Priority", "Weight (kg)");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        const char *priority_str;
        switch(dp[i].priority) {
            case 1: priority_str = "High"; break;
            case 2: priority_str = "Medium"; break;
            case 3: priority_str = "Low"; break;
            default: priority_str = "Unknown";
        }
        printf("%-20s %-12.2f %-10s %-10.2f\n",
               dp[i].name, dp[i].distance, priority_str, dp[i].weight);
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
            // Compare distances
            if (dp[j].distance > dp[j + 1].distance) {
                // Swap the entire structures
                temp = dp[j];
                dp[j] = dp[j + 1];
                dp[j + 1] = temp;
            }
        }
    }
}

// Sort by priority (1 -> 2 -> 3)
void sortByPriority(struct DeliveryPoint dp[], int n) {
    struct DeliveryPoint temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Compare priorities
            if (dp[j].priority > dp[j + 1].priority) {
                // Swap the entire structures
                temp = dp[j];
                dp[j] = dp[j + 1];
                dp[j + 1] = temp;
            }
        }
    }
}

// Calculate total battery required (based on distance AND weight)
float totalBatteryRequired(struct DeliveryPoint dp[], int n) {
    float total_consumption = 0;
    // Assume consumption rate is 1 unit/km for base travel,
    // plus 0.1 units/kg/km for payload.
    // The drone must fly *to* the point and *return* to base.

    for (int i = 0; i < n; i++) {
        // One-way consumption with payload: distance * (1 + weight / 10.0f)
        float consumption_to_point = dp[i].distance * (1 + dp[i].weight / 10.0f);

        // Return consumption (empty drone): distance * 1.0f
        float consumption_return = dp[i].distance * 1.0f;

        total_consumption += consumption_to_point + consumption_return;
    }
    return total_consumption;
}

// Optimized route (Simple Heuristic: Prioritize Shortest Distance for single-trip deliveries)
void optimizedRoute(struct DeliveryPoint dp[], int n) {
    // A simple optimization for *multiple single-trip* deliveries
    // is to serve the nearest point first to minimize initial drain.
    // We sort the list by distance, but it doesn't represent a true
    // *multi-stop* route optimization (like TSP), which is too complex for this project.
    sortByDistance(dp, n);

    printf("\n## Optimized Route (Single Trip Deliveries - Shortest First) ##\n");
    printf("This assumes the drone returns to base after each delivery.\n");

    for (int i = 0; i < n; i++) {
        printf("%d. Base -> %s (%.2f km, Priority %d)\n",
               i + 1, dp[i].name, dp[i].distance, dp[i].priority);
    }
    printf("\nRoute complete. Drone returns to Base after the last delivery.\n");
}
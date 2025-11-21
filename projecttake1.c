#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing parcel data
struct Parcel {
    int parcelID;
    char receiver[50];
    char address[100];
    char status[20];
    char routeZone[20];
    struct Parcel *next;
};

// Head pointer for linked list
struct Parcel *head = NULL;

// Predefined delivery zones stored in an array
char zones[5][20] = {"Zone-A", "Zone-B", "Zone-C", "Zone-D", "Zone-E"};

// Function to add a new parcel
void addParcel() {
    struct Parcel *newNode = (struct Parcel *)malloc(sizeof(struct Parcel));

    printf("\nEnter Parcel ID: ");
    scanf("%d", &newNode->parcelID);

    printf("Enter Receiver Name: ");
    scanf(" %[^\n]", newNode->receiver);

    printf("Enter Delivery Address: ");
    scanf(" %[^\n]", newNode->address);

    printf("\nChoose Delivery Zone (0-4):\n");
    for(int i = 0; i < 5; i++)
        printf("%d. %s\n", i, zones[i]);

    int choice;
    scanf("%d", &choice);
    strcpy(newNode->routeZone, zones[choice]);

    strcpy(newNode->status, "Pending");
    newNode->next = NULL;

    // Insert at end of linked list
    if(head == NULL) {
        head = newNode;
    } else {
        struct Parcel *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("\nParcel Added Successfully!\n");
}

// Function to display all parcel records
void showParcels() {
    if(head == NULL) {
        printf("\nNo parcels available.\n");
        return;
    }

    struct Parcel *temp = head;
    printf("\n--- Parcel List ---\n");
    while(temp != NULL) {
        printf("\nParcel ID: %d\n", temp->parcelID);
        printf("Receiver: %s\n", temp->receiver);
        printf("Address: %s\n", temp->address);
        printf("Route Zone: %s\n", temp->routeZone);
        printf("Status: %s\n", temp->status);
        temp = temp->next;
    }
}

// Function to update delivery status
void updateStatus() {
    int id;
    printf("\nEnter Parcel ID to update status: ");
    scanf("%d", &id);

    struct Parcel *temp = head;
    while(temp != NULL) {
        if(temp->parcelID == id) {
            printf("Enter new status (Pending/Out for Delivery/Delivered): ");
            scanf(" %[^\n]", temp->status);
            printf("Status Updated Successfully!\n");
            return;
        }
        temp = temp->next;
    }

    printf("Parcel not found.\n");
}

// Function to delete delivered parcels
void deleteDelivered() {
    struct Parcel *temp = head;
    struct Parcel *prev = NULL;

    while(temp != NULL) {
        if(strcmp(temp->status, "Delivered") == 0) {
            if(prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("\nDelivered parcel removed.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("\nNo delivered parcels to delete.\n");
}

// Function to search by parcel ID
void searchParcel() {
    int id;
    printf("\nEnter Parcel ID to search: ");
    scanf("%d", &id);

    struct Parcel *temp = head;
    while(temp != NULL) {
        if(temp->parcelID == id) {
            printf("\nParcel Found:\n");
            printf("Receiver: %s\n", temp->receiver);
            printf("Address: %s\n", temp->address);
            printf("Zone: %s\n", temp->routeZone);
            printf("Status: %s\n", temp->status);
            return;
        }
        temp = temp->next;
    }

    printf("\nParcel not found.\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n\n----- SMART PARCEL DELIVERY MANAGEMENT SYSTEM -----\n");
        printf("1. Add Parcel\n");
        printf("2. Show Parcels\n");
        printf("3. Update Status\n");
        printf("4. Delete Delivered Parcel\n");
        printf("5. Search Parcel\n");
        printf("6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addParcel(); break;
            case 2: showParcels(); break;
            case 3: updateStatus(); break;
            case 4: deleteDelivered(); break;
            case 5: searchParcel(); break;
            case 6: exit(0);
            default: printf("Invalid Choice!\n");
        }
    }
    return 0;
}

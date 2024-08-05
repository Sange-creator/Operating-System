// C program demonstrating the producer-consumer problem:

#include <stdio.h>
#include <stdlib.h>

// Initialize a mutex to 1
int mutex = 1;

// Number of full slots as 0
int full = 0;

// Number of empty slots as size of buffer
int empty = 10, x = 0;

// Function to produce an item and add it to the buffer
void producer() {
    --mutex;  // Decrease mutex by 1
    ++full;   // Increase number of full slots by 1
    --empty;  // Decrease empty slots
    x++;
    printf("\nProducer produces item %d", x);
    ++mutex;  // Increase mutex by 1
}

// Function to consume an item and remove it from the buffer
void consumer() {
    --mutex;  // Decrease mutex by 1
    --full;   // Decrease number of full slots by 1
    ++empty;  // Increase empty slots
    printf("\nConsumer consumes item %d", x);
    x--;
    ++mutex;  // Increase mutex by 1
}

int main() {
    int n;
    while (1) {
        printf("\n1. Press 1 for Producer");
        printf("\n2. Press 2 for Consumer");
        printf("\n3. Press 3 for Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &n);

        // Switch cases
        switch (n) {
            case 1:
                if ((mutex == 1) && (empty != 0)) {
                    producer();
                } else {
                    printf("Buffer is full");
                }
                break;

            case 2:
                if ((mutex == 1) && (full != 0)) {
                    consumer();
                } else {
                    printf("Buffer is empty!");
                }
                break;

            case 3:
                exit(0);
                break;

            default:
                printf("Invalid choice!");
                break;
        }
    }
    return 0;
}

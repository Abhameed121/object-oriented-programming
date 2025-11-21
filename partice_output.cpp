#include <iostream>
using namespace std;

int main() {
    int *intArrayPtr;  // Pointer for dynamic array
    int *temp;         // Temporary pointer to hold the base address

    // Dynamically allocate memory for 5 integers
    intArrayPtr = new int[5];

    // Initialize the first element
    *intArrayPtr = 7;

    // Temporary pointer to keep track of the original start
    temp = intArrayPtr;

    // Fill the array with values based on the previous element
    for (int i = 1; i < 5; i++) {
        intArrayPtr++;  // Move to the next element
        *intArrayPtr = *(intArrayPtr - 1) + 2 * i;  // Set value based on previous element
    }

    // Reset pointer back to the beginning
    intArrayPtr = temp;

    // Print the array values
    for (int i = 0; i < 5; i++) {
        cout << *intArrayPtr << " ";  // Dereference pointer to print value
        intArrayPtr++;  // Move to the next element
    }
    cout << endl;

    // Deallocate the dynamically allocated memory
    delete[] temp;

    return 0;
}

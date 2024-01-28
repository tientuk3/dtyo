#include <iostream>
#include <cstring>

int main() {
    // Possible memory leak and undefined behavior
    int* ptr = new int[10];
    ptr[10] = 50; // Writing out of bounds

    // Potential false positive for uninitialized variable usage
    int x;
    for (int i = 0; i < 10; ++i) {
        if (i == 5) {
            x = 10;
        }
    }
    std::cout << "Value of x: " << x << std::endl; // x may be uninitialized

    // Dangerous use of strcpy leading to buffer overflow
    char source[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit";
    char destination[10];
    strcpy(destination, source); // Buffer overflow

    delete[] ptr; // Properly deleting the allocated memory
    return 0;
}
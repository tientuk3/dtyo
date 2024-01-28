#include <iostream>
#include <cstring>

int main() {

    int* ptr = new int[10];
    ptr[10] = 50;


    int x;
    for (int i = 0; i < 10; ++i) {
        if (i == 5) {
            x = 10;
        }
    }
    std::cout << "Value of x: " << x << std::endl;


    char source[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit";
    char destination[10];
    strcpy(destination, source);

    delete[] ptr;
    return 0;
}
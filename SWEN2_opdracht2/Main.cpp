// SWEN2_opdracht2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>


int main()
{
    std::cout << "Hello SWEN Opdracht 2!\n";

    // Feature 1 - CLI

    int randArray[20];

    for (int i = 0; i < 20; i++) {
        randArray[i] = rand() % 100;  //Generate number between 0 to 99
    }
    std::cout << "\nElements of the array: " << std::endl;

    for (int i = 0; i < 20; i++) {
        std::cout << "Elements no " << i + 1 << ": " << randArray[i] << std::endl;
    }

    return 0;
}

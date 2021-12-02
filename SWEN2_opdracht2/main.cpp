// SWEN2_opdracht2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>

    // Feature 2 - bubble sort
int* bubbleSort(int arr[])
{
    static int bubbleArray[20];

    int temp;

    for (int i = 0; i < 20; i++)
    {
        bubbleArray[i] = arr[i];
    }
    for (int i = 0; i < 20; i++) {
        for (int j = i + 1; j < 20; j++)
        {
            if (bubbleArray[j] < bubbleArray[i]) {
                temp = bubbleArray[i];
                bubbleArray[i] = bubbleArray[j];
                bubbleArray[j] = temp;
            }
        }
    }
    return bubbleArray;
}


int main()
{
    std::cout << "Hello SWEN Opdracht 2!\n";

    // Feature 1 - CLI

    int randArray[20];
    int *bubbleArray;
    for (int i = 0; i < 20; i++) {
        randArray[i] = rand() % 100;  //Generate number between 0 to 99
    }
    std::cout << "\nElements of the array: " << std::endl;

    for (int i = 0; i < 20; i++) {
        std::cout << "Elements no " << i + 1 << ": " << randArray[i] << std::endl;
    }

    bubbleArray = bubbleSort(randArray);
    for (int i = 0; i < 20; i++) {
        std::cout << "Elements no " << i + 1 << ": " << bubbleArray[i] << std::endl;
    }

    return 0;
}

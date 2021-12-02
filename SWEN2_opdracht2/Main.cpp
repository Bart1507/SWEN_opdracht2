// SWEN2_opdracht2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>

    // Feature 2 - bubble sort
int* bubbleSort(int arr[], int size)
{
    static int bubbleArray[20];

    int temp;

    for (int i = 0; i < size; i++)
    {
        bubbleArray[i] = arr[i];
    }
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++)
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



void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        std::swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main()
{
    std::cout << "Hello SWEN Opdracht 2!\n";

    // FEATURE 1 - CLI
    char charArray[10] = { 'g','h','s','y','e','u','b','a','k','n' };
    int charArrayToInt[10];
    char bubbleCharArray[10];
    char mergeCharArray[10];
    char heapCharArray[10];
    int randArray[20];
    int *bubbleArray;
    int mergeArray[20];
    int heapArray[20];
    for (int i = 0; i < 20; i++) {
        randArray[i] = rand() % 100;  //Generate number between 0 to 99
    }
    std::cout << "\nElements of the array: " << std::endl;

    for (int i = 0; i < 20; i++) {
        std::cout << "Elements no " << i + 1 << ": " << randArray[i] << std::endl;
    }
    std::cout << "\n" << std::endl;


    // FEATURE 2 - Bubble sort

    bubbleArray = bubbleSort(randArray, 20);
    for (int i = 0; i < 20; i++) {
        std::cout << "BubbleElements no " << i + 1 << ": " << bubbleArray[i] << std::endl;
    }
    std::cout << "\n" << std::endl;

    // FEATURE 3 - Merge sort

    //copy to merge array
    for (int i = 0; i < 20; i++) {
        mergeArray[i] = randArray[i];
    }
    mergeSort(mergeArray, 0, 19);
    for (int i = 0; i < 20; i++) {
        std::cout << "MergeElements no " << i + 1 << ": " << mergeArray[i] << std::endl;
    }
    std::cout << "\n" << std::endl;

    // FEATURE 3 - Heap sort

    //copy to heap array
    for (int i = 0; i < 20; i++) {
        heapArray[i] = randArray[i];
    }

    int heapSize = sizeof(heapArray) / sizeof(heapArray[0]);
    heapSort(heapArray, heapSize);
    for (int i = 0; i < 20; i++) {
        std::cout << "HeapElements no " << i + 1 << ": " << heapArray[i] << std::endl;
    }
    std::cout << "\n" << std::endl;

    //char

    for (int i = 0; i < 10; i++) {
        std::cout << "CharElements no " << i + 1 << ": " << charArray[i] << std::endl;
    }
    std::cout << "\n" << std::endl;


    //copy char to int

    for (int i = 0; i < 10; i++) {
        charArrayToInt[i] = (int)charArray[i];
    }
    std::cout << "\n" << std::endl;

    // FEATURE 2 - Bubble sort

    bubbleArray = bubbleSort(charArrayToInt, 10);
    for (int i = 0; i < 10; i++) {
        bubbleCharArray[i] = bubbleArray[i];
    }
    for (int i = 0; i < 10; i++) {
        std::cout << "BubbleElements no " << i + 1 << ": " << bubbleCharArray[i] << std::endl;
    }
    std::cout << "\n" << std::endl;

    // FEATURE 3 - Merge sort

    //copy to merge array
    for (int i = 0; i < 10; i++) {
        mergeArray[i] = charArrayToInt[i];
    }
    mergeSort(mergeArray, 0, 9);
    for (int i = 0; i < 10; i++) {
        mergeCharArray[i] = mergeArray[i];
    }
    for (int i = 0; i < 10; i++) {
        std::cout << "MergeElements no " << i + 1 << ": " << mergeCharArray[i] << std::endl;
    }
    std::cout << "\n" << std::endl;

    // FEATURE 3 - Heap sort

    //copy to heap array
    for (int i = 0; i < 10; i++) {
        heapArray[i] = charArrayToInt[i];
    }

    int heapSizeChar = sizeof(heapArray) / sizeof(heapArray[0]);
    heapSort(heapArray, 10);

    for (int i = 0; i < 10; i++) {
        heapCharArray[i] = heapArray[i];
    }
    for (int i = 0; i < 10; i++) {
        std::cout << "HeapElements no " << i + 1 << ": " << heapCharArray[i] << std::endl;
    }
    std::cout << "\n" << std::endl;


    return 0;
}
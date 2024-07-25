#include <iostream>

// Function to calculate Fibonacci numbers
void calculateFibonacci(int n, int* fibArray) {
    if (n >= 1) fibArray[0] = 0;
    if (n >= 2) fibArray[1] = 1;

    for (int i = 2; i < n; ++i) {
        fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
    }
}

// Function to calculate factorial
unsigned long long factorial(int num) {
    if (num == 0) return 1;
    unsigned long long result = 1;
    for (int i = 1; i <= num; ++i) {
        result *= i;
    }
    return result;
}

// Function to calculate factorials for the Fibonacci sequence
void calculateFactorials(int n, int* fibArray, unsigned long long* factArray) {
    for (int i = 0; i < n; ++i) {
        factArray[i] = factorial(fibArray[i]);
    }
}

int main() {
    int n;

    std::cout << "Enter the number of Fibonacci terms: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;
    }

    // Dynamic memory allocation for arrays
    int* fibArray = new int[n];
    unsigned long long* factArray = new unsigned long long[n];

    // Calculate Fibonacci sequence
    calculateFibonacci(n, fibArray);

    // Calculate factorials for each Fibonacci number
    calculateFactorials(n, fibArray, factArray);

    // Display the results
    std::cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; ++i) {
        std::cout << fibArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Factorials of Fibonacci sequence: ";
    for (int i = 0; i < n; ++i) {
        std::cout << factArray[i] << " ";
    }
    std::cout << std::endl;

    // Free dynamically allocated memory
    delete[] fibArray;
    delete[] factArray;

    return 0;
}

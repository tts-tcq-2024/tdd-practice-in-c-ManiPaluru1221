#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER 1000

int add(const char* numbers);
void SplitNumbers(const char* numbers, const char* delimiters, int* splitNumbers, int* count);
void ValidateNumbers(int* numbers, int count);

int main() {
    const char* input = "1,2,1001,3";
    int result = add(input);
    printf("Result: %d\n", result);
    return 0;
}

int add(const char* numbers) {
    if (numbers == NULL || strlen(numbers) == 0) {
        return 0;
    }

    const char* delimiters = ",\n";
    int splitNumbers[100];
    int count = 0;
    SplitNumbers(numbers, delimiters, splitNumbers, &count);
    ValidateNumbers(splitNumbers, count);

    int sum = 0;
    for (int i = 0; i < count; i++) {
        if (splitNumbers[i] <= MAX_NUMBER) {
            sum += splitNumbers[i];
        }
    }

    return sum;
}

void SplitNumbers(const char* numbers, const char* delimiters, int* splitNumbers, int* count) {
    char temp[1000];
    strcpy(temp, numbers);

    char* token = strtok(temp, delimiters);
    while (token != NULL) {
        splitNumbers[(*count)++] = atoi(token);
        token = strtok(NULL, delimiters);
    }
}

void ValidateNumbers(int* numbers, int count) {
    for (int i = 0; i < count; i++) {
        if (numbers[i] < 0) {
            printf("Negatives not allowed: %d\n", numbers[i]);
            exit(1);
        }
    }
}

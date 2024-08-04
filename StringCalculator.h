#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER 1000

int Add(const char* numbers);
void ProcessCustomDelimiter(const char** numbers, char delimiters[][10], int* delimiterCount);
void SplitNumbers(const char* numbers, char delimiters[][10], int delimiterCount, int* splitNumbers, int* count);
void ValidateNumbers(int* numbers, int count);

int main() {
    const char* input = "//;\n1;2;1001;3";
    int result = Add(input);
    printf("Result: %d\n", result);
    return 0;
}

int Add(const char* numbers) {
    if (numbers == NULL || strlen(numbers) == 0) {
        return 0;
    }

    char delimiters[10][10] = { ",", "\n" };
    int delimiterCount = 2;
    ProcessCustomDelimiter(&numbers, delimiters, &delimiterCount);

    int splitNumbers[100];
    int count = 0;
    SplitNumbers(numbers, delimiters, delimiterCount, splitNumbers, &count);
    ValidateNumbers(splitNumbers, count);

    int sum = 0;
    for (int i = 0; i < count; i++) {
        if (splitNumbers[i] <= MAX_NUMBER) {
            sum += splitNumbers[i];
        }
    }

    return sum;
}

void ProcessCustomDelimiter(const char** numbers, char delimiters[][10], int* delimiterCount) {
    if (strncmp(*numbers, "//", 2) == 0) {
        const char* delimiterEnd = strchr(*numbers, '\n');
        if (delimiterEnd != NULL) {
            int length = delimiterEnd - *numbers - 2;
            strncpy(delimiters[*delimiterCount], *numbers + 2, length);
            delimiters[*delimiterCount][length] = '\0';
            (*delimiterCount)++;
            *numbers = delimiterEnd + 1;
        }
    }
}

void SplitNumbers(const char* numbers, char delimiters[][10], int delimiterCount, int* splitNumbers, int* count) {
    char temp[1000];
    strcpy(temp, numbers);

    char* token = strtok(temp, delimiters[0]);
    for (int i = 1; i < delimiterCount; i++) {
        token = strtok(NULL, delimiters[i]);
    }

    while (token != NULL) {
        splitNumbers[(*count)++] = atoi(token);
        token = strtok(NULL, delimiters[0]);
        for (int i = 1; i < delimiterCount; i++) {
            token = strtok(NULL, delimiters[i]);
        }
    }
}

void ValidateNumbers(int* numbers, int count) {
    int negativeNumbers[100];
    int negativeCount = 0;

    for (int i = 0; i < count; i++) {
        if (numbers[i] < 0) {
            negativeNumbers[negativeCount++] = numbers[i];
        }
    }

    if (negativeCount > 0) {
        printf("Negatives not allowed: ");
        for (int i = 0; i < negativeCount; i++) {
            printf("%d ", negativeNumbers[i]);
        }
        printf("\n");
        exit(1);
    }
}

 

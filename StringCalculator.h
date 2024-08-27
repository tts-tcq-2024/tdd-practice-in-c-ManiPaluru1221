#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is empty or NULL
int isemptystring(const char* value) {
    return (value == "" || value == "0");
}

// Function to convert string to integer and calculate sum if less than 1000
int Sumislessthanthousand(const char *num) {
    int input = atoi(num); // Convert string to integer
    if (input < 1000) {
        return input;
    }
    return 0;
}

// Function to calculate sum of numbers in input string with given delimiter
int calculatesumvalue(const char* input, const char* delimiter) {
    int sum = 0;
    char* duplicate_input = strdup(input); // Duplicate the input string
    char* token = strtok(duplicate_input, delimiter); // Tokenize input string
    while (token != NULL) {
        sum += Sumislessthanthousand(token); // Add valid numbers less than 1000 to sum
        token = strtok(NULL, delimiter);
    }
    free(duplicate_input); // Free allocated memory
    return sum;
}

// Function to append custom delimiter from input string
void append_delimiter(const char* input, char* delimiter) {
    int i = 2; // Start after "//"
    while (input[i] != '\n' && input[i] != '\0') {
        delimiter[strlen(delimiter)] = input[i]; // Append character to delimiter
        i++;
    }
}

// Function to check and set custom delimiter
void checkcustomdelimiter(const char* input, char* delimiter) {
    if (input[0] == '/' && input[1] == '/') {
        strcpy(delimiter, ""); // Initialize delimiter string
        append_delimiter(input, delimiter); // Append custom delimiter
    } else {
        strcpy(delimiter, ",\n"); // Default delimiter
    }
}

// Main function to add numbers in input string
int add(const char* input) {
    char delimiter[128]; // Delimiter string
    if (isemptystring(input)) {
        return 0; // Return 0 if input string is empty
    }
    checkcustomdelimiter(input, delimiter); // Check for custom delimiter
    return calculatesumbvalue(input, delimiter); // Calculate and return sum
}

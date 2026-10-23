#include <stdio.h>

int main() {
    char choice;
    float input_temp, converted_temp;

    printf("--- Temperature Converter ---\n");
    printf("C. Convert Celsius to Fahrenheit\n");
    printf("F. Convert Fahrenheit to Celsius\n");
    printf("Enter your choice (C or F): ");
    scanf(" %c", &choice); // Note the space before %c to catch newline characters

    if (choice == 'C' || choice == 'c') {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &input_temp);

        // Correct formula using floating-point math (9.0 / 5.0 = 1.8)
        converted_temp = (input_temp * 9.0 / 5.0) + 32.0;
        printf("%.2f° Celsius is equal to %.2f° Fahrenheit\n", input_temp, converted_temp);
    }
    else if (choice == 'F' || choice == 'f') {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &input_temp);

        // Correct formula using floating-point math (5.0 / 9.0)
        converted_temp = (input_temp - 32.0) * 5.0 / 9.0;
        printf("%.2f° Fahrenheit is equal to %.2f° Celsius\n", input_temp, converted_temp);
    }
    else {
        printf("Invalid choice! Please restart and enter C or F.\n");
    }

    return 0;
}

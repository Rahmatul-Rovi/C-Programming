#include <stdio.h>

int main() {
    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);

    if ((ch >= 'A' && ch <= 'Z') ||
        (ch >= 'a' && ch <= 'z')) {
        printf("It is an alphabet");
    }
    else {
        printf("It is not an alphabet");
    }

    return 0;
}

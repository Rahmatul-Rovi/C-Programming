
#include <stdio.h>

int largest(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Largest = %d", largest(a, b));

    return 0;
}


#include <stdio.h>

long fact(int n) {
    long f = 1;
    for (int i = 2; i <= n; i++) f *= i;
    return f;
}

int isStrong(int n) {
    int temp = n;
    long sum = 0;
    while (temp > 0) {
        sum += fact(temp % 10);
        temp /= 10;
    }
    return sum == n;
}

int main() {
    int start, end;
    printf("Enter range (start end): ");
    scanf("%d %d", &start, &end);
    printf("Strong numbers: ");
    for (int i = start; i <= end; i++)
        if (isStrong(i)) printf("%d ", i);
    printf("\n");
    return 0;
}

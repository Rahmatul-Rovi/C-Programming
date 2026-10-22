#include <stdio.h>
#include <math.h>

int countDigits(int n) {
    int count = 0;
    while (n > 0) { count++; n /= 10; }
    return count;
}

int isArmstrong(int n) {
    int temp = n, digits = countDigits(n);
    long sum = 0;
    while (temp > 0) {
        sum += (long)pow(temp % 10, digits);
        temp /= 10;
    }
    return sum == n;
}

int main() {
    int start, end;
    printf("Enter range (start end): ");
    scanf("%d %d", &start, &end);
    printf("Armstrong numbers: ");
    for (int i = start; i <= end; i++)
        if (isArmstrong(i)) printf("%d ", i);
    printf("\n");
    return 0;
}

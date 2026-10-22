#include<stdio.h>

int max(int a, int b) {return (a>b) ? a:b;}
int min(int a, int b) {return (a<b) ? a:b;}

int main(){
int a, b;
printf("Enter two numbers:");
scanf("%d %d", &a, &b);
printf("Maximum= %d\n", max(a,b));
printf("Minimum= %d\n", min(a,b));
return 0;
}

#include<stdio.h>

int cube(int n){
 return n*n*n;
 }

 int main(){
 int n;
 printf("Enter a number:");
 scanf("%d", &n);

 printf("Cube of %d = %d\n", n, cube(n));
 return n;
 }

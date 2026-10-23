#include<stdio.h>

int main(){
int m,n;
printf("Enter two numbers:");
scanf("%d %d", &m,&n);
if(m>n){
    printf("%d is Maximum number");
}
else{
    printf("%d is Minium Number");
}
return 0;
}

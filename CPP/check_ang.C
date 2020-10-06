#include<stdio.h>
int main()
{ int N,i,j,k=0,t,B;

printf("Enter a number\n");
scanf("%d",&N);
B=N;
while(N>0)
{
 t=N%10;
 k+=t*t*t;
 N/=10;
}
if(k==B)
printf("It is an angstrom number");
else
printf("It is not an angstrom number");
}
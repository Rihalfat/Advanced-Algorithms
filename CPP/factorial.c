#include<stdio.h>
int main()
{ int N,i,F=1;
printf("Enter a number");
scanf("%d",&N);
for(i=1;i<=N;i++)
F*=i;
printf("\n %d",F);
}
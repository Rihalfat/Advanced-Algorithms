#include<stdio.h>
int main()
{ int N,i,j,check;

printf("Enter a number\n");
scanf("%d",&N);
for(i=2;i<=N;i++)
{
check=1;
for(j=2;j<i;j++)
 if(i%j==0)
 {check=0;
  break;
  }
if(check==1)
printf("%d ",i);
}

}
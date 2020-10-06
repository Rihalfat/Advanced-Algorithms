//menuarithmetic
#include<stdio.h>
#include<conio.h>
void main()
{
	int a, b, c, n, s;
	printf("Enter two numbers as a and b\na: ");
	scanf("%d", &a);
	printf("b: ");
	scanf("%d", &b);
	printf("\nChoose an option below\n");
	printf("1: Add\n2: Subtract\n3: Multiply\n4: Divide\n5: Modulus\n");
	scanf("%d", &n);
	switch(n)
	{
		case 1: c=a+b;
				printf("\nSum is %d", c);
				break;
		case 2: printf("\nFor a-b, press 1; for b-a, press 2\n");
				scanf("%d", &s);
				if(s==1)
				 {
				  c=a-b;
				  printf("\nDifference is %d", c);
			     }
				else if(s==2)
				      {
		               c=b-a;
				       printf("\nDifference is %d", c);
				      }
				else
				 printf("\nInvalid option");
				break;
		case 3: c=a*b;
				printf("\nProduct is %d", c);
				break;
		case 4: printf("\nFor a/b, press 1; for b/a, press 2\n");
				scanf("%d", &s);
				if(s==1)
				 {
				  c=a/b;
				  printf("\nQuotient is %d", c);
		         }
				else if(s==2)
					  {
					   c=b/a;
					   printf("\nQuotient is %d", c);
				      }
				else 
				 printf("\nInvalid option");
				break;
		case 5: printf("\nFor a%%b, press 1; for b%%a, press 2\n");
				scanf("%d", &s);
				if(s==1)
				 {
				  c=a%b;
				  printf("\nRemainder is %d", c);
			     } 
				else if(s==2)
					  {
					   c=b%a;
					   printf("\nRemainder is %d", c);
				      }
				else 
				 printf("\nInvalid option");
				break;
		default: printf("\nInvalid option");						
	}
	getch();
}

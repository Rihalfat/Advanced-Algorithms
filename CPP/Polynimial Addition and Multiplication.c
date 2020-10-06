#include<stdio.h>
#include<stdlib.h>
struct poly
{
    int c,e;
};
int reduce(int k,struct poly p3[k]);
void initialize(int x,struct poly p[x])
{
    int i=0;
    for(;i<x;i++)
    {   
        printf("ENTER TERM %d COEFFECIENT: ",(i+1));
        scanf("%d",&p[i].c);
        printf("ENTER TERM %d EXPONENT: ",(i+1));
        scanf("%d",&p[i].e);
    }
}
void arrange(int x,struct poly p[x])
{
    int i,j;
    struct poly temp;
    for(i=0;i<x-1;i++)
    {
        for(j=0;j<x-i-1;j++)
        {
            if(p[j].e<p[j+1].e)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}
void display(int x,struct poly p[x])
{
    int i;
    for(i=0;i<x;i++)
    {    if (i==(x-1))
            printf("%dx^%d",p[i].c,p[i].e);
        else    
            printf("%dx^%d + ",p[i].c,p[i].e);
    }
    printf("\n");
}
void add(int x,int t1,int t2,struct poly p1[t1],struct poly p2[t2],struct poly p3[x])
{
    int i=0,j=0,k=0;
    while(i<t1&&j<t2)
    {
        if (p1[i].e==p2[j].e)
        {
            p3[k].c=p1[i].c+p2[j].c;
            p3[k].e=p1[i].e;
            i++,j++,k++;
        }
        else if (p1[i].e>p2[j].e)
        {
            p3[k].c=p1[i].c;
            p3[k].e=p1[i].e;
            k++,i++;
        }
        else
        {
            p3[k].c=p2[j].c;
            p3[k].e=p2[j].e;
            k++,j++;
        }
    }
    while(i<t1)
    {
        p3[k].c=p1[i].c;
        p3[k].e=p1[i].e;
        i++,k++;
    }
    while(j<t2)
    {
        p3[k].c=p2[j].c;
        p3[k].e=p2[j].e;
        j++,k++;
    }
    display(k,p3);
}
void mul(int x,int t1,int t2,struct poly p1[t1],struct poly p2[t2],struct poly p3[x])
{
    int i,j,k=0;
    for(i=0;i<t1;i++)
    {
        for(j=0;j<t2;j++)
        {
            p3[k].c=p1[i].c*p2[j].c;
            p3[k].e=p1[i].e+p2[j].e;
            k++;
        }
    }
    reduce(k,p3);
}
int reduce(int k,struct poly p3[k])
{
    int x=p3[0].e;
    int n=x+1;
    int a[n];
    int i,j;
    for(i=0;i<n;i++)
        a[i]=0;
   
    for(i=0;i<k;i++)
    {
        j=p3[i].e;
        a[j]=p3[i].c+a[j];
    }
    for(i=x,j=0;i>=0;i--)
    {
        
        if(a[i]==0)
            continue;
        p3[j].e=i;
        p3[j].c=a[i];
        j++;
    }
    display(j,p3);
    return j;
}
void calculate(int x)
{
    if(x>2||x<1)
    {
        if (x==3)
            exit(0);
        else    
            printf("ENTER CORRECT CHOICE \n");
    }        
    else
    {
        int t1,t2;
        printf("ENTER THE NUMBER OF TERMS IN FIRST EXPRESSION:");
        scanf("%d",&t1);
        struct poly p1[t1];
        initialize(t1,p1);
        printf("ENTER THE NUMBER OF TERMS IN SECOND EXPRESSION:");
        scanf("%d",&t2);
        struct poly p2[t2];
        initialize(t2,p2);
        arrange(t1,p1);
        arrange(t2,p2);
        t1=reduce(t1,p1);
        t2=reduce(t2,p2);
        if(x==1)
        {   x=t1+t2;
            struct poly p3[x];
            add(x,t1,t2,p1,p2,p3);
        }    
        else
        {   x=t1*t2;
            struct poly p3[x];
            mul(x,t1,t2,p1,p2,p3);
        }
    }    
}
void main()
{
    int x;
    while(1)
    {
        printf("OPTION \n");
        printf("1.ADDITION\n");
        printf("2.MULTIPLICATION \n");
        printf("3.EXIT \n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d",&x);
        calculate(x);
    }
}

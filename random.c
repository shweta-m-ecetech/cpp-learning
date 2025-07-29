#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int num,c,d=0,n1,n3,count,j,k,m,i,sum,b,n2,a;
    printf("Enter the number between 6 digits and 12 digits:");
    scanf("%d",&num);
    n1=num;
    count=0;
    sum=0;
    for(i=0;n1!=0;i++)
    {
        n1=n1/10;
        count=count+1;
    }
    printf("%d",count);
    n3=num;
    for(k=1;n3!=0;k++)
    {
        c=n3/pow(10,(count-k));
        n3=n3-c*pow(10,count-k);
        if(c!=0)
        {
            if(k>=count-1)
            {
                d=c*pow(10,count-k)+d;
            }
        }
        else if(c==0 && k==count-1)
        {
            d=0;
        }
        else 
        {
            d=d*10+d;
        }
    }
    printf("\n%d",d);
    n2=num;
    b=0;
    for(j=1;j<=count;j++)
    {
        a=n2/pow(10,(count-j));
        n2=n2-a*pow(10,count-j);
        if(a!=0)
        {
            if(j<4)
            {
                b=b*10+a;
            }
        }
        else//possible only when j=2,3 not 1(since first digit isnt 0)
        {
            if(j<4)
            {
                b=b*10;
            }
            
        }
    }
    printf("\n%d",b);

    return 0; 
}    
//CALCULATING NO. OF ATLAS NO.S & ARMSTRONG NO.S BETWEEN LAST 2 DIGITS AND FIRST 3 DIGITS OF A GIVEN NO.
//27.10
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int num,n1,n2,a,b,c,d=0,n3,n4,n5,count,j,k,m,i,p,sum,n6,n,n7,sum1,l;
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
    n3=num;
    d=0;
    for(k=1;n3!=0;k++)
    {
        c=n3/pow(10,(count-k));
        n3=n3-c*pow(10,count-k);
        if(c!=0)
        {
            if(k==count-1)
            {
                d=c*10+d;
            }
            else if(k==count)
            {
                d=d+c;
            }
        }
        else if(c==0 && k==count-1)
        {
            d=0;
        }
        else if(c==0 && k==count)
        {
            d=d*10;

        }
    }
    printf("\n%d\n",d);
    n4=0;
    for(m=d;m<=b;m++)
    {
        n5=m;
        sum=0;
        for(p=1;n5!=0;p++)
        {
            sum=sum+(n5%10);
            n5=n5/10;
        }
        if(m%sum==0)
        {
            n4=n4+1;
            printf("\n%d",m);
        }
        else
        {
            n4=n4+0;
        } 
        
    }
    printf("\n%d\n",n4);//-->ATLAS NO_S
    //CALCULATING NO. OF ARMSTRONG NO.S
    n7=0;
    for(n=d;n<=b;n++)
    {
        n6=n;
        sum1=0;
        for(l=1;n6!=0;l++)
        {
            sum1=sum1+pow((n6%10),3);
            n6=n6/10;
        }
        if(n%sum1==0)
        {
            n7=n7+1;
            printf("\n%d",n);
        }
    }
    printf("\n%d\n",n7);//-->ARMSTRONG NO.S

    int n8=0,t,rev,g,h,s,e=0;
    int n9=0,n10,u,w,y=0,prime[b-d],f;
    for(u=d;u<=b;u++)
    {
        for(w=2;w<u;w++)
        {
            if(u%w!=0)
            {
                n9=n9+1;
                break;
            }
        }
        if(n9==0)
        {
            h=u;
            rev=0;
            for(g=1;h!=0;g++)
            {
                rev=h%10+rev*10;
                h=h/10;   
            }
            for(s=2;s<rev;s++)
            {
                if(rev%s!=0)
                {
                    n10=n10+1;
                    break;
                }
                   
            } 
            if(n10==0)
            {
                y=y+1;
                printf("\n%d",&u);
            }     
            
        }
       
        
    }
    printf("\n\n%d",y);


    return 0; 
}
//Check for a palindrome
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n,rev,n1,i;
    printf("Enter a number:");
    scanf("%d",&n);
    rev=0;
    n1=n;
    for(i=1;n1!=0;i++)
    {
        rev=rev*10+n1%10;
        n1=n1/10;
    }
    if(n==rev)
    {
        printf("\nThe number is a palindrome.");

    }
    else
    {
        printf("\nThe number isnt a palindrome.");
        printf("\n%d",rev);
    }
    return 0; 


}
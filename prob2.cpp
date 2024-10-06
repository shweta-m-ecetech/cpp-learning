#include<stdio.h>
#include<math.h>
//#define PROB1 1
#define PROB2 2

int main()
{

#ifdef PROB1    
    int add.1, da_1;
    printf("Enter a number"); 
    scanf("%d",&add.1,&da_1); 
    printf("%d",add.1+da_1); 
#else

int n=3; 
scanf("%d",&n);
int* p=(int*)malloc(n*sizeof(int));
for(int i=0;i<n;i++)
{
    p[i]=(int)pow(i,3);
}

for(int i=0;i<n;i++)
{
    printf("%d %d %d\n",i,p[i],&p[i]);
}
free(p);
p=nullptr;

#endif

return 0;
}

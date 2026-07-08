#include <stdio.h>

void main()
{
    int a[3][3];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = i+1; j < 3; j++)
        {
            if(a[i][j] > a[i][j+1])
            {
                int t = a[i][j];
                a[i][j] = a[i][j+1];
                a[i][j+1] = t;
            }
        }
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = i+1; j < 3; j++)
        {
            if(a[i][j] > a[i+1][j])
            {
                int t = a[i][j];
                a[i][j] = a[i+1][j];
                a[i+1][j] = t;
            }
        }
    }

    for(int i = 0; i < 2; i++)
    {
        if(a[i][i] > a[i+1][i+1])
        {
            int t = a[i][i];
            a[i][i] = a[i+1][i+1];
            a[i+1][i+1] = t;
        }
    }

    for(int i = 0; i < 2; i++)
    {
        for(int j = i + 1; j < 2; j++)
        {
            if(a[i][2-i] > a[j][2-j])
            {
                int t = a[i][2-i];
                a[i][2-i] = a[j][2-j];
                a[j][2-j] = t;
            }
        }
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,a,b,i,j,temporary,x,y;
    /*Step 1. Creating final and temporary matrix, filling and outputing the final matrix*/
    m = 3 + rand()%1;
    n = 4 + rand()%1;
    printf("%d %d \n\n", m, n);
    a = m - 1;
    b = n -1;
    int matrix[m][n];
    int temp[a][b];

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            matrix[i][j] = rand()%10;

    for (i = 0; i < m; i++)
    {
        for (j = 0;j < n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    printf("\n\n");

    /*Step 2. Reversing matrix and printing it out.*/
     for(i = 0; i < n; i++)
    {
        temporary = matrix[0][i];
        matrix[0][i] = matrix[m - 1][n - 1 - i];
        matrix[m - 1][n - 1 - i] = temporary;

    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    printf("\n\n");

    /*Step 3. Detecting the least element of the matrix and deleting its col and row in temp matrix.*/
    temporary = 82;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (matrix[i][j] < temporary)
            {
                temporary = matrix[i][j];
                x = i;
                y = j;
            }

    for (i = x; i < m - 1; i++)
        for (j = 0; j < n; j++)
            matrix[i][j] = matrix[i+1][j];

    for (i = 0; i < m; i++)
        for (j = y; j < n - 1; j++)
            matrix[i][j] = matrix[i][j+1];

    for (i = 0; i < a; i++)
        for (j = 0; j < b; j++)
            temp[i][j] = matrix[i][j];

    for (i = 0; i < a; i++)
    {
        for (j = 0; j < b; j++)
            printf("%d ", temp[i][j]);
        printf("\n");
    }
    printf("\n\n");

    /*Step 4. Very 'slojna' algorithm of inputing and formating new matrix.*/
    char matr[100],t[5];
    int temp1[100],e=0;
    x=0;
    y=0;
    for(i=0; i<5; i++)
    {
        t[i]='\0';
    }
    for(i=0; i<100; i++)
    {
        temp1[i]='\0';
    }

    fgets(matr,100, stdin);

    for(i=0; i<100; i++)
    {
        if(matr[i]=='.' || matr[i]==',')
        {
            x++;
        }
    }

    for(i=0; i<100; i++)
    {
        if(matr[i]==',' || matr[i]==' ' || matr[i]=='.')
        {
            if (matr[i]==',')
            {
                y++;
                break;
            }
            y++;
        }
    }
    int matr2[x][y];
        j=0;
        for(i=0; i<100; i++)
        {
            if (matr[i]-'0'>=0 && matr[i]-'0'<=9)
            {
                char a;
                a = matr[i];
                t[j] = a;
                j=j+1;
            } else if (matr[i]=='.' || matr[i]==' ')
            {
                  temp1[e]=atoi(t);
                  e++;
                  for(j=0; j<5; j++)
                  {
                      t[j]='\0';
                  }
                  j=0;
            }
        }

        e=0;

        for(i=0; i<x; i++)
        {
            for(j=0; j<y; j++)
            {
                matr2[i][j]=temp1[e];
                e++;
            }
        }

    printf("\n");

    for(i=0; i<x; i++)
    {
        for(j=0; j < y; j++)
        {
            printf("%d ",matr2[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    if (y==a)
    {
        int k=x,l=a,z;
        int matrix3[k][l];


        for(i=0; i<k; i++)
        {
            for(j=0; j<l; j++)
            {
                printf("%d ",matrix3[i][j]);
            }
            printf("\n");
        }
        for (i=0; i < x; i++)
        {
            int end=0;
            for (j=0; j < a; j++)
            {
                for (z=0; z < y; z++)
                {
                    end+=matr2[i][z] * temp[z][j];
                }
            printf("%d",end);
            }
            printf("\n");
        }
        printf("\n\n");
    }

    return 1;
}

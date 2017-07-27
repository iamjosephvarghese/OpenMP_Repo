//Simple C Program  to find transpose of first matrix and add it to the second matrix

#include<stdio.h>
#include<time.h>

void main()
{
 int a[5][5],b[5][5],c[5][5],i=0,j=0,temp=0;
 for(i=0;i<5;i++)
  {
   for(j=0;j<5;j++)
    {
     printf("Enter elements of first matrix:");
     scanf("%d",&a[i][j]);
   }
 }


 for(i=0;i<5;i++)
  {
   for(j=0;j<5;j++)
    {
     printf("Enter elements of second matrix:");
     scanf("%d",&b[i][j]);
   }
 }

 printf("\nThe First Matrix is:\n");
 for(i = 0; i < 5; i++)
  {
   for(j = 0; j < 5; j++)
    {
     printf("%d\t", a[i][j]);
    }
    printf("\n");
  }



 printf("\nThe Second Matrix is:\n");
 for(i = 0; i < 5; i++)
  {
   for(j = 0; j < 5; j++)
    {
     printf("%d\t", b[i][j]);
    }
    printf("\n");
  }

clock_t begin = clock();
for(i = 0; i < 5; i++)
  {
   for(j = 0; j < i; j++)
    {
     temp = a[i][j];
     a[i][j] = a[j][i];
     a[j][i] = temp;
    }
  }

 printf("\nTranspose of First Matrix:\n");
 for(i = 0; i < 5; i++)
  {
   for(j = 0; j < 5; j++)
    {
     printf("%d\t", a[i][j]);
    }
    printf("\n");
  }

 for(i = 0; i < 5;i++)
  {
   for(j = 0; j < 5;j++)
    {
     c[i][j] = a[i][j] + b[i][j];
    }
  }

clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

printf("CPU Time used = %lfms",time_spent);

 printf("\nSum Matrix Is:\n");
 for(i = 0; i < 5; i++)
  {
   for(j = 0; j < 5; j++)
    {
     printf("%d\t", c[i][j]);
    }
    printf("\n");
  }


}

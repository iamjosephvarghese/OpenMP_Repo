//Transpose with locks

#include<stdio.h>
#include<time.h>
#include<omp.h>

void main()
{
 int a[5][5],b[5][5],c[5][5],temp=0,ch;
 printf("Menu\n1.Express Mode\n2.Custom Mode\n");
 printf("Enter your choice:");
 scanf("%d",&ch);

 if(ch == 1)
 {
  int l = 1;
  for(int i=0;i<5;i++)
  {
    for(int j=0;j<5;j++)
    {
      a[i][j] = l;
      b[i][j] = 1;
      l++;
    }

   }

 }else{
   int k=1;
  for(int i=0;i<5;i++)
  {
   for(int j=0;j<5;j++)
    {
     printf("Enter element %d of first matrix:",k);
     scanf("%d",&a[i][j]);
     k++;
   }
 }
 k = 1;
 for(int i=0;i<5;i++)
  {
   for(int j=0;j<5;j++)
    {
     printf("Enter element %d of second matrix:",k);
     scanf("%d",&b[i][j]);
     k++;
   }
  }
 }


 printf("\nThe First Matrix is:\n");
 for(int i = 0; i < 5; i++)
  {
   for(int j = 0; j < 5; j++)
    {
     printf("%d\t", a[i][j]);
    }
    printf("\n");
  }



 printf("\nThe Second Matrix is:\n");
 for(int i = 0; i < 5; i++)
  {
   for(int j = 0; j < 5; j++)
    {
     printf("%d\t", b[i][j]);
    }
    printf("\n");
  }

clock_t begin = clock();

omp_lock_t writelock;
omp_init_lock(&writelock);

#pragma omp parallel num_threads(5)
{
 #pragma omp for
 for(int i = 0; i < 5; i++)
  {
    int id = omp_get_thread_num();
   for(int j = 0; j < i; j++)
    {

     omp_set_lock(&writelock);
     temp = a[i][j];
     a[i][j] = a[j][i];
     a[j][i] = temp;
     omp_unset_lock(&writelock);

    }
    printf("Thread %d\n",id);
  }
 }

 omp_destroy_lock(&writelock);

 printf("\nTranspose of First Matrix:\n");
 for(int i = 0; i < 5; i++)
  {
   for(int j = 0; j < 5; j++)
    {
     printf("%d\t", a[i][j]);
    }
    printf("\n");
  }
#pragma omp parallel num_threads(5)
 {
  #pragma omp for
  for(int i = 0; i < 5;i++)
  {
    int id = omp_get_thread_num();
   for(int j = 0; j < 5;j++)
    {
     c[i][j] = a[i][j] + b[i][j];
    }
    printf("Thread %d\n",id);
  }
}

clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

printf("CPU Time used = %lfms",time_spent);

 printf("\nSum Matrix Is:\n");
 for(int i = 0; i < 5; i++)
  {
   for(int j = 0; j < 5; j++)
    {
     printf("%d\t", c[i][j]);
    }
    printf("\n");
  }

}

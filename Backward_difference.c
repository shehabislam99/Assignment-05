#include <stdio.h>

void backwardDifferenceTable(double y[][10], int n)
{
     for (int i = 1; i < n; i++)
     {
          for (int j = n - 1; j >= i; j--)
          {
               y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
          }
     }
}

void printBackwardDifferenceTable(double y[][10], int n)
{
     printf("\nBackward Difference Table:\n");
     printf("y");
     for (int i = 1; i < n; i++)
     {
          printf("\t\t∇%d", i);
     }
     printf("\n");

     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j <= i; j++)
          {
               printf("%.6f\t", y[i][j]);
          }
          printf("\n");
     }
}

int main()
{
     int n;
     printf("Enter number of data points: ");
     scanf("%d", &n);

     double y[n][10];

     printf("Enter y values:\n");
     for (int i = 0; i < n; i++)
     {
          scanf("%lf", &y[i][0]);
     }

     backwardDifferenceTable(y, n);
     printBackwardDifferenceTable(y, n);

     return 0;
}
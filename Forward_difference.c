#include <stdio.h>

void forwardDifferenceTable(double y[][10], int n)
{
     for (int i = 1; i < n; i++)
     {
          for (int j = 0; j < n - i; j++)
          {
               y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
          }
     }
}

void printForwardDifferenceTable(double y[][10], int n)
{
     printf("\nForward Difference Table:\n");
     printf("y");
     for (int i = 1; i < n; i++)
     {
          printf("\t\tΔ%d", i);
     }
     printf("\n");

     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < n - i; j++)
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

     forwardDifferenceTable(y, n);
     printForwardDifferenceTable(y, n);

     return 0;
}
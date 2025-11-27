#include <stdio.h>

void dividedDifferenceTable(double x[], double y[][10], int n)
{
     for (int i = 1; i < n; i++)
     {
          for (int j = 0; j < n - i; j++)
          {
               y[j][i] = (y[j][i - 1] - y[j + 1][i - 1]) / (x[j] - x[j + i]);
          }
     }
}

void printDividedDifferenceTable(double x[], double y[][10], int n)
{
     printf("\nNewton's Divided Difference Table:\n");
     printf("x\t\ty");
     for (int i = 1; i < n; i++)
     {
          printf("\t\tΔ%d", i);
     }
     printf("\n");

     for (int i = 0; i < n; i++)
     {
          printf("%.2f", x[i]);
          for (int j = 0; j < n - i; j++)
          {
               printf("\t\t%.6f", y[i][j]);
          }
          printf("\n");
     }
}

int main()
{
     int n;
     printf("Enter number of data points: ");
     scanf("%d", &n);

     double x[n];
     double y[n][10];

     printf("Enter data points (x y):\n");
     for (int i = 0; i < n; i++)
     {
          scanf("%lf %lf", &x[i], &y[i][0]);
     }

     dividedDifferenceTable(x, y, n);
     printDividedDifferenceTable(x, y, n);

     return 0;
}
#include <stdio.h>
#include <math.h>
#define MAX 100

void Forward_DifferenceTable(double x[MAX], double y[MAX][MAX], int n)
{
     for (int i = 1; i < n; i++)
     {
          for (int j = 0; j < n - i; j++)
          {
               y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
          }
     }
     printf("\nForward Difference Table:\n");
     printf("x(i)\t\tf(xi)");
     for (int i = 1; i < n; i++)
          printf("\t\t Delta%d", i);
     printf("\n");

     for (int i = 0; i < n; i++)
     {
          printf("%.1f", x[i]);
          for (int j = 0; j < n - i; j++)
               printf("\t\t %.2f", y[i][j]);
          printf("\n");
     }
}

int main()
{
     int n;
     double x[MAX], y[MAX][MAX];
     printf("Enter the number of value data: ");
     scanf("%d", &n);

     printf("Entervalue of x and y:\n");
     for (int i = 0; i < n; i++)
          scanf("%lf %lf", &x[i], &y[i][0]);

     Forward_DifferenceTable(x, y, n);

     return 0;
}
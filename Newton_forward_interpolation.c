#include <stdio.h>
#include <math.h>
#define MAX 100

void Newton_ForwardInterpolation(double x[MAX], double y[MAX][MAX], int n, double find_value)
{
     double h, p, xi, Li;
     h = x[1] - x[0];
     p = (find_value - x[0]) / h;
     xi = y[0][0];
     Li = 1.0;

     for (int i = 1; i < n; i++)
     {
          for (int j = 0; j < n - i; j++)
          {
               y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
          }
     }

     for (int i = 1; i < n; i++)
     {
          Li = Li * (p - (i - 1)) / i;
          xi = xi + Li * y[0][i];
     }

     printf("Newton Forward interpolation Value at  f(%.2f) = %.3f\n", find_value, xi);
}

int main()
{
     int n;
     double x[MAX], y[MAX][MAX], find_value;

     printf("Enter the number of value data: ");
     scanf("%d", &n);

     printf("Enter value of x and y:\n");
     for (int i = 0; i < n; i++)
          scanf("%lf %lf", &x[i], &y[i][0]);

     printf("Enter interpolation value point x: ");
     scanf("%lf", &find_value);

     Newton_ForwardInterpolation(x, y, n, find_value);

     return 0;
}
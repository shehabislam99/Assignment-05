#include <stdio.h>
#include <math.h>
#define MAX 100

void Newton_BackwardInterpolation(double x[MAX], double y[MAX][MAX], int n, double find_value)
{
     double h, p, xi, Li;
     h = x[1] - x[0];
     p = (find_value - x[n - 1]) / h;
     xi = y[n - 1][0];
     Li = 1.0;

     for (int i = 1; i < n; i++)
     {
          for (int j = n - 1; j >= i; j--)
          {
               y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
          }
      }

     for (int i = 1; i < n; i++)
     {
          Li = Li * (p + (i - 1)) / i;
          xi = xi + Li * y[n - 1][i];
         
     }

     printf("Newton Backward interpolation Value at  f(%.2f) = %.3f\n", find_value, xi);
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

     Newton_BackwardInterpolation(x, y, n, find_value);

     return 0;
}
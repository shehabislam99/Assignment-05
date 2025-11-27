#include <stdio.h>
#include <math.h>
#define MAX 1000

void Lagrange_Interpolation(double x[MAX], double y[MAX], int n, double find_value)
{
     double xi = 0.0;
     for (int i = 0; i < n; i++)
     {
          double Li = y[i];
          for (int j = 0; j < n; j++)
          {
               if (j != i)
               {
                    Li = Li * ((find_value - x[j]) / (x[i] - x[j]));
               }
          }
          xi += Li;
     }
     printf("Lagrange Interpolation value at f(%.2f) = %.3lf\n", find_value, xi);
}

int main()
{
     int n;
     double x[MAX], y[MAX], find_value;

     printf("Enter the number of value data: ");
     scanf("%d", &n);

     printf("Enter the value of x and y:\n");
     for (int i = 0; i < n; i++)
     {
          scanf("%lf %lf", &x[i], &y[i]);
     }

     printf("Enter interpolation value point x: ");
     scanf("%lf", &find_value);

     Lagrange_Interpolation(x, y, n, find_value);

     return 0;
}
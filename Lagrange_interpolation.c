#include <stdio.h>
#include <math.h>
#define MAX 1000

double Lagrange_Interpolation(double x[MAX], double y[MAX], int n, double find_value)
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
     return xi;
}

int main()
{
     int n;
     double x[MAX], y[MAX], find_value, xi;

     printf("Enter the number of value data: ");
     scanf("%d", &n);

     printf("Enter the value of x and y:\n");
     for (int i = 0; i < n; i++)
     {
          scanf("%lf %lf", &x[i], &y[i]);
     }

     printf("Enter the value of x: ");
     scanf("%lf", &find_value);

     xi = Lagrange_Interpolation(x, y, n, find_value);
     printf("Lagrange Interpolation value is f(x) = %.6lf\n", xi);

     return 0;
}
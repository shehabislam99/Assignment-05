#include <stdio.h>

double newtonBackwardInterpolation(double x[], double y[][10], int n, double xp)
{
     double h = x[1] - x[0];
     double u = (xp - x[n - 1]) / h;
     double result = y[n - 1][0];
     double term = u;

     for (int i = 1; i < n; i++)
     {
          for (int j = n - 1; j >= i; j--)
          {
               y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
          }
     }

   
     double factorial = 1.0;
     for (int i = 1; i < n; i++)
     {
          factorial *= i;
          result += (term * y[n - 1][i]) / factorial;
          term *= (u + i);
     }

     return result;
}

int main()
{
     int n;
     printf("Enter number of data points: ");
     scanf("%d", &n);

     double x[n], y[n][10];

     printf("Enter data points (x y):\n");
     for (int i = 0; i < n; i++)
     {
          scanf("%lf %lf", &x[i], &y[i][0]);
     }

     double xp;
     printf("Enter interpolation point: ");
     scanf("%lf", &xp);

     double result = newtonBackwardInterpolation(x, y, n, xp);
     printf("Interpolated value at %.2f = %.6f\n", xp, result);

     return 0;
}
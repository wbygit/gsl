/* This is an automatically generated file created by
   convert_double_to_int.pl -- do not edit                */

#include <math.h>
#include <gsl_statistics_int.h>

double 
gsl_stats_int_absdev (const int data[], unsigned int n)
{
  double mean = gsl_stats_int_mean(data, n);
  return gsl_stats_int_absdev_with_mean(data, n, mean);
}
    
double 
gsl_stats_int_absdev_with_mean (const int data[], unsigned int n, double mean)
{
  /* takes an integer dataset and finds the absolute deviation */

  double sum = 0, absdev;
  unsigned int i;

  /* find the sum of the absolute deviations */
  for (i = 0; i < n; i++)
    {
      double delta = fabs(data[i] - mean);
      sum += delta;
    }

  absdev = sum / n;

  return absdev;
}


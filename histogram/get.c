#include <config.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_histogram.h>

double
gsl_histogram_get (const gsl_histogram * h, size_t i)
{
  const size_t n = h->n;

  if (i >= n)
    {
      GSL_ERROR_RETURN ("index lies outside valid range of 0 .. n - 1",
			GSL_EDOM, 0);
    }

  return h->bin[i];
}

int
gsl_histogram_get_range (const gsl_histogram * h, size_t i,
			 double *lower, double *upper)
{
  const size_t n = h->n;

  if (i >= n)
    {
      GSL_ERROR ("index lies outside valid range of 0 .. n - 1", GSL_EDOM);
    }

  *lower = h->range[i];
  *upper = h->range[i + 1];

  return GSL_SUCCESS;
}

/* Author:  G. Jungman
 * RCS:     $Id$
 */
#include <math.h>
#include <gsl_math.h>
#include "gsl_sf_chebyshev.h"
#include "gsl_sf_bessel.h"

/* chebyshev expansions for amplitude and phase
   functions used in bessel evaluations
   
   These are the same for J0,Y0 and for J1,Y1, so
   they sit outside those functions.
*/
	
static double bm0_data[21] = {
   .09284961637381644,
  -.00142987707403484,
   .00002830579271257,
  -.00000143300611424,
   .00000012028628046,
  -.00000001397113013,
   .00000000204076188,
  -.00000000035399669,
   .00000000007024759,
  -.00000000001554107,
   .00000000000376226,
  -.00000000000098282,
   .00000000000027408,
  -.00000000000008091,
   .00000000000002511,
  -.00000000000000814,
   .00000000000000275,
  -.00000000000000096,
   .00000000000000034,
  -.00000000000000012,
   .00000000000000004
}; 
      
static double bth0_data[24] = {
  -.24639163774300119,
   .001737098307508963,
  -.000062183633402968,
   .000004368050165742,
  -.000000456093019869,
   .000000062197400101,
  -.000000010300442889,
   .000000001979526776,
  -.000000000428198396,
   .000000000102035840,
  -.000000000026363898,
   .000000000007297935,
  -.000000000002144188,
   .000000000000663693,
  -.000000000000215126,
   .000000000000072659,
  -.000000000000025465,
   .000000000000009229,
  -.000000000000003448,
   .000000000000001325,
  -.000000000000000522,
   .000000000000000210,
  -.000000000000000087,
   .000000000000000036
};

const struct gsl_sf_ChebSeries _bessel_amp_phase_bm0_cs = {
  bm0_data,
  20,
  -1, 1,
  (double *)0,
  (double *)0
};

const struct gsl_sf_ChebSeries _bessel_amp_phase_bth0_cs = {
  bth0_data,
  23,
  -1, 1,
  (double *)0,
  (double *)0
};


static double bm1_data[21] = {
   .1047362510931285, 
   .00442443893702345,
  -.00005661639504035,
   .00000231349417339,
  -.00000017377182007,
   .00000001893209930,
  -.00000000265416023,
   .00000000044740209,
  -.00000000008691795,
   .00000000001891492,
  -.00000000000451884,
   .00000000000116765,
  -.00000000000032265,
   .00000000000009450,
  -.00000000000002913,
   .00000000000000939,
  -.00000000000000315,
   .00000000000000109,
  -.00000000000000039,
   .00000000000000014,
  -.00000000000000005,
}; 
  
static double bth1_data[24] = {
   .74060141026313850, 
  -.004571755659637690,
   .000119818510964326,
  -.000006964561891648,
   .000000655495621447,
  -.000000084066228945,
   .000000013376886564,
  -.000000002499565654,
   .000000000529495100,
  -.000000000124135944,
   .000000000031656485,
  -.000000000008668640,
   .000000000002523758,
  -.000000000000775085,
   .000000000000249527,
  -.000000000000083773,
   .000000000000029205,
  -.000000000000010534,
   .000000000000003919,
  -.000000000000001500,
   .000000000000000589,
  -.000000000000000237,
   .000000000000000097,
  -.000000000000000040,
};

const struct gsl_sf_ChebSeries _bessel_amp_phase_bm1_cs = {
  bm1_data,
  20,
  -1, 1,
  (double *)0,
  (double *)0
};

const struct gsl_sf_ChebSeries _bessel_amp_phase_bth1_cs = {
  bth1_data,
  23,
  -1, 1,
  (double *)0,
  (double *)0
};

double gsl_sf_bessel_asymp_Mnu(const double nu, const double x)
{
  double x_inv  = 1./x;
  double x_inv2 = x_inv*x_inv;
  double mu     = 4.*nu*nu;
  double Mnu2_c = 2./(M_PI) * (1. + (mu-1.)/8. * x_inv2
                                  + (mu-1.)*(mu-9.)*3./128. * x_inv2*x_inv2
                              );
  return sqrt(Mnu2_c)/sqrt(x); /* do it this way so we can never underflow */
}

double gsl_sf_bessel_asymp_thetanu(const double nu, const double x)
{
  double x_inv  = 1./x;
  double x_inv2 = x_inv*x_inv;
  double mu     = 4.*nu*nu;
  return x * (1. - (0.5*nu + 0.25)*M_PI*x_inv 
	         + (mu-1.)/8. * x_inv2
                 + (mu-1.)*(mu-25.)/384. * x_inv2*x_inv2
	     );
}

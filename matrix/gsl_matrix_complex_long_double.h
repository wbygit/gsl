#ifndef __GSL_MATRIX_COMPLEX_LONG_DOUBLE_H__
#define __GSL_MATRIX_COMPLEX_LONG_DOUBLE_H__

#include <stdlib.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_vector_complex_long_double.h>

#undef __BEGIN_DECLS
#undef __END_DECLS
#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS /* empty */
# define __END_DECLS /* empty */
#endif

__BEGIN_DECLS

typedef struct gsl_matrix_complex_long_double_struct gsl_matrix_complex_long_double;

struct gsl_matrix_complex_long_double_struct 
{
  size_t size1;
  size_t size2;
  size_t tda;
  long double * data;
  gsl_block_complex_long_double * block;
} ;


gsl_matrix_complex_long_double * 
gsl_matrix_complex_long_double_alloc (const size_t n1, const size_t n2);

gsl_matrix_complex_long_double * 
gsl_matrix_complex_long_double_calloc (const size_t n1, const size_t n2);

gsl_matrix_complex_long_double * 
gsl_matrix_complex_long_double_alloc_from_block (gsl_block_complex_long_double * b, 
                                           const size_t offset, 
                                           const size_t n1, const size_t n2, const size_t d2);

gsl_matrix_complex_long_double * 
gsl_matrix_complex_long_double_alloc_from_matrix (gsl_matrix_complex_long_double * b,
                                            const size_t k1, const size_t k2,
                                            const size_t n1, const size_t n2);

gsl_vector_complex_long_double * 
gsl_vector_complex_long_double_alloc_row_from_matrix (gsl_matrix_complex_long_double * m,
                                                const size_t i);

gsl_vector_complex_long_double * 
gsl_vector_complex_long_double_alloc_col_from_matrix (gsl_matrix_complex_long_double * m,
                                                const size_t j);


void gsl_matrix_complex_long_double_free (gsl_matrix_complex_long_double * m);

void gsl_matrix_complex_long_double_set_zero (gsl_matrix_complex_long_double * m);
void gsl_matrix_complex_long_double_set_identity (gsl_matrix_complex_long_double * m);
void gsl_matrix_complex_long_double_set_all (gsl_matrix_complex_long_double * m, gsl_complex_long_double x);

gsl_complex_long_double * gsl_matrix_complex_long_double_ptr(const gsl_matrix_complex_long_double * m, const size_t i, const size_t j);
gsl_complex_long_double gsl_matrix_complex_long_double_get(const gsl_matrix_complex_long_double * m, const size_t i, const size_t j);
void gsl_matrix_complex_long_double_set(gsl_matrix_complex_long_double * m, const size_t i, const size_t j, const gsl_complex_long_double x);

int gsl_matrix_complex_long_double_fread (FILE * stream, gsl_matrix_complex_long_double * m) ;
int gsl_matrix_complex_long_double_fwrite (FILE * stream, const gsl_matrix_complex_long_double * m) ;
int gsl_matrix_complex_long_double_fscanf (FILE * stream, gsl_matrix_complex_long_double * m);
int gsl_matrix_complex_long_double_fprintf (FILE * stream, const gsl_matrix_complex_long_double * m, const char * format);

int gsl_matrix_complex_long_double_memcpy(gsl_matrix_complex_long_double * dest, const gsl_matrix_complex_long_double * src);

int gsl_matrix_complex_long_double_swap_rows(gsl_matrix_complex_long_double * m, const size_t i, const size_t j);
int gsl_matrix_complex_long_double_swap_columns(gsl_matrix_complex_long_double * m, const size_t i, const size_t j);
int gsl_matrix_complex_long_double_swap_rowcol(gsl_matrix_complex_long_double * m, const size_t i, const size_t j);


gsl_matrix_complex_long_double gsl_matrix_complex_long_double_submatrix (gsl_matrix_complex_long_double * m, size_t i, size_t j, size_t n1, size_t n2);
gsl_vector_complex_long_double gsl_matrix_complex_long_double_row (gsl_matrix_complex_long_double * m, size_t i);
gsl_vector_complex_long_double gsl_matrix_complex_long_double_column (gsl_matrix_complex_long_double * m, size_t j);
gsl_vector_complex_long_double gsl_matrix_complex_long_double_diagonal (gsl_matrix_complex_long_double * m);

/***********************************************************************/
/* The functions below are obsolete                                    */
/***********************************************************************/
int gsl_matrix_complex_long_double_get_row(gsl_vector_complex_long_double * v, const gsl_matrix_complex_long_double * m, const size_t i);
int gsl_matrix_complex_long_double_get_col(gsl_vector_complex_long_double * v, const gsl_matrix_complex_long_double * m, const size_t j);
int gsl_matrix_complex_long_double_set_row(gsl_matrix_complex_long_double * m, const size_t i, const gsl_vector_complex_long_double * v);
int gsl_matrix_complex_long_double_set_col(gsl_matrix_complex_long_double * m, const size_t j, const gsl_vector_complex_long_double * v);

int gsl_vector_complex_long_double_view_row_from_matrix (gsl_vector_complex_long_double * v, gsl_matrix_complex_long_double * m, const size_t i);
int gsl_vector_complex_long_double_view_col_from_matrix (gsl_vector_complex_long_double * v, gsl_matrix_complex_long_double * m, const size_t j);

int gsl_matrix_complex_long_double_view_from_vector (gsl_matrix_complex_long_double * m, gsl_vector_complex_long_double * base, const size_t offset, const size_t n1, const size_t n2, const size_t d2);

extern int gsl_check_range ;

#ifdef HAVE_INLINE

extern inline 
gsl_complex_long_double
gsl_matrix_complex_long_double_get(const gsl_matrix_complex_long_double * m, 
		     const size_t i, const size_t j)
{
  const gsl_complex_long_double zero = {{0,0}};

#ifndef GSL_RANGE_CHECK_OFF
  if (i >= m->size1)
    {
      GSL_ERROR_RETURN("first index out of range", GSL_EINVAL, zero) ;
    }
  else if (j >= m->size2)
    {
      GSL_ERROR_RETURN("second index out of range", GSL_EINVAL, zero) ;
    }
#endif
  return *(gsl_complex_long_double *)(m->data + 2*(i * m->tda + j)) ;
} 

extern inline 
void
gsl_matrix_complex_long_double_set(gsl_matrix_complex_long_double * m, 
		     const size_t i, const size_t j, const gsl_complex_long_double x)
{
#ifndef GSL_RANGE_CHECK_OFF
  if (i >= m->size1)
    {
      GSL_ERROR_RETURN_NOTHING("first index out of range", GSL_EINVAL) ;
    }
  else if (j >= m->size2)
    {
      GSL_ERROR_RETURN_NOTHING("second index out of range", GSL_EINVAL) ;
    }
#endif
  *(gsl_complex_long_double *)(m->data + 2*(i * m->tda + j)) = x ;
}
#endif /* HAVE_INLINE */

__END_DECLS

#endif /* __GSL_MATRIX_COMPLEX_LONG_DOUBLE_H__ */

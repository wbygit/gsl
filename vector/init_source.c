TYPE (gsl_vector) *
FUNCTION (gsl_vector, alloc) (const size_t n)
{
  TYPE (gsl_block) * block;
  TYPE (gsl_vector) * v;

  if (n == 0)
    {
      GSL_ERROR_RETURN ("vector length n must be positive integer",
			GSL_EDOM, 0);
    }

  v = (TYPE (gsl_vector) *) malloc (sizeof (TYPE (gsl_vector)));

  if (v == 0)
    {
      GSL_ERROR_RETURN ("failed to allocate space for vector struct",
			GSL_ENOMEM, 0);
    }

  block = FUNCTION (gsl_block,alloc) (n);

  if (block == 0)
    {
      free (v) ;

      GSL_ERROR_RETURN ("failed to allocate space for block",
			GSL_ENOMEM, 0);
    }
      
  v->data = block->data ;
  v->size = n;
  v->stride = 1;
  v->block = block;

  return v;
}

TYPE (gsl_vector) *
FUNCTION (gsl_vector, calloc) (const size_t n)
{
  size_t i;

  TYPE (gsl_vector) * v = FUNCTION (gsl_vector, alloc) (n);

  if (v == 0)
    return 0;

  /* initialize vector to zero */

  for (i = 0; i < MULTIPLICITY * n; i++)
    {
      v->data[i] = 0;
    }

  return v;
}

TYPE (gsl_vector) *
FUNCTION (gsl_vector, alloc_from_block) (TYPE(gsl_block) * block, 
                                         const size_t offset, 
                                         const size_t n, 
                                         const size_t stride)
{
  TYPE (gsl_vector) * v;

  if (n == 0)
    {
      GSL_ERROR_RETURN ("vector length n must be positive integer",
			GSL_EDOM, 0);
    }

  if (stride == 0)
    {
      GSL_ERROR_RETURN ("stride must be positive integer", GSL_EDOM, 0);
    }

  if (block->size <= offset + (n - 1) * stride)
    {
      GSL_ERROR_RETURN ("vector would extend past end of block", GSL_EDOM, 0);
    }

  v = (TYPE (gsl_vector) *) malloc (sizeof (TYPE (gsl_vector)));

  if (v == 0)
    {
      GSL_ERROR_RETURN ("failed to allocate space for vector struct",
			GSL_ENOMEM, 0);
    }

  v->data = block->data + offset ;
  v->size = n;
  v->stride = stride;
  v->block = block;

  return v;
}

TYPE (gsl_vector) *
FUNCTION (gsl_vector, alloc_from_vector) (TYPE(gsl_vector) * w, 
                                         const size_t offset, 
                                         const size_t n, 
                                         const size_t stride)
{
  TYPE (gsl_vector) * v;

  if (n == 0)
    {
      GSL_ERROR_RETURN ("vector length n must be positive integer",
			GSL_EDOM, 0);
    }

  if (stride == 0)
    {
      GSL_ERROR_RETURN ("stride must be positive integer", GSL_EDOM, 0);
    }

  if (offset + (n - 1) * stride >= w->size)
    {
      GSL_ERROR_RETURN ("vector would extend past end of block", GSL_EDOM, 0);
    }

  v = (TYPE (gsl_vector) *) malloc (sizeof (TYPE (gsl_vector)));

  if (v == 0)
    {
      GSL_ERROR_RETURN ("failed to allocate space for vector struct",
			GSL_ENOMEM, 0);
    }

  v->data = w->data + w->stride * offset ;
  v->size = n;
  v->stride = stride * w->stride;
  v->block = 0;

  return v;
}


void
FUNCTION (gsl_vector, free) (TYPE (gsl_vector) * v)
{
  if (v->block)
    {
      FUNCTION(gsl_block, free) (v->block) ;
    }
  free (v);
}





/*
 * define C headers for the fortran library function and subroutine defs
 */
#ifdef __cplusplus
#define extern extern "C"
#endif

extern int add_func(const int* a, const int* b);
extern void add_sub(const int* a, const int* b, int* c);
extern void add_explicit_shape_mats(const int* a, const int* b, int* c, const int* ncol, const int* nrow);

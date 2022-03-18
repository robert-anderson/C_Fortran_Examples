
/*
 * define C headers for the fortran library function and subroutine defs
 * and provide aliases with cleaner names
 */
extern int __my_module_MOD_add_func(const int* a, const int* b);
int add_func(const int* a, const int* b){
    return __my_module_MOD_add_func(a, b);
}
extern void __my_module_MOD_add_sub(const int* a, const int* b, int* c);
void add_sub(const int* a, const int* b, int* c){
    __my_module_MOD_add_sub(a, b, c);
}
extern void __my_module_MOD_add_explicit_shape_mats(const int* a, const int* b, int* c, const int* ncol, const int* nrow);
void add_explicit_shape_mats(const int* a, const int* b, int* c, const int* ncol, const int* nrow) {
    __my_module_MOD_add_explicit_shape_mats(a, b, c, ncol, nrow);
}


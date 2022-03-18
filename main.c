#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "my_interface.h"


int main(int argc, char** argv){
    int a = 123;
    int b = 456;
    /*
     * simple check of interoperability with a return value
     */
    int c = add_func(&a, &b);
    assert(c==579);
    /*
     * simple check of interoperability without a return value
     */
    c = 0;
    add_sub(&a, &b, &c);
    assert(c==579);

    /*
     * dynamically allocate the matrices
     */
    const int nrow=2, ncol=3;
    int* amat = calloc(nrow*ncol, sizeof(int));
    int* bmat = calloc(nrow*ncol, sizeof(int));
    for (int i=0ul; i<nrow*ncol; ++i) {
        amat[i] = i*2;
        bmat[i] = i*3;
    }
    int* cmat = calloc(nrow*ncol, sizeof(int));
    add_explicit_shape_mats(amat, bmat, cmat, &ncol, &nrow);
    for (int i=0ul; i<nrow*ncol; ++i) {
        assert(cmat[i]==i*5);
    }
    return 0;
}

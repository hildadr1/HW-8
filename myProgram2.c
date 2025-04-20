#include "matrix2.h"
int main(){
    Matrix a = create(2,3);
    addingElements(&a, 0, 0, 1);
    addingElements(&a, 0, 1, 2);
    addingElements(&a, 0, 2, 3);
    addingElements(&a, 1, 0, 4);
    addingElements(&a, 1, 1, 5);
    addingElements(&a, 1, 2, 6);


    // Matrix b = create(2,2);
    // addingElements(&b, 0, 0, 1);
    // addingElements(&b, 0, 1, 2);
    // addingElements(&b, 1, 0, 3);
    // addingElements(&b, 1, 1, 4);
    Matrix c = matrixTranspose(&a);
    print(&c);
    printf("\n");
    print(&a);
    return 0;
}
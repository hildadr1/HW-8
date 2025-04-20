/*
  Author: Hilda Rodriguez
 */
#include "matrix.h"

int main(){

  Matrix A(2,2);
  A.add(0,0,6);
  A.add(0,1,4);
  A.add(1,0,8);
  A.add(1,1,3);
  cout << "Matrix A " << endl;
  A.print();
  cout << endl;

  Matrix B(2,3);
  B.add(0,0,1);
  B.add(0,1,2);
  B.add(0,2,3);
  B.add(1,0,4);
  B.add(1,1,5);
  B.add(1,2,6);
  cout << "Matrix B" << endl;
  B.print();
  cout << endl;

  Matrix C(2,3);
  C.add(0,0,2);
  C.add(0,1,4);
  C.add(0,2,6);
  C.add(1,0,1);
  C.add(1,1,3);
  C.add(1,2,5);
  cout << "Matrix C" << endl;
  C.print();
  cout << endl;
  Matrix matrixOne = B*3;
  cout << "Scalar multiplication" << endl;
  matrixOne.print();
  cout << endl;

  Matrix matrixTwo = C.transpose();
  cout << "Matrix Transpose" << endl;
  matrixTwo.print();
  cout << endl;

  Matrix BC = matrixOne * matrixTwo;
  cout << "Matrix Multiplication" << endl;
  BC.print();
  cout << endl;
  Matrix D = A + (B*3) * C.transpose();
  D.print();
  return 0;
}
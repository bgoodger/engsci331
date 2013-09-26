
#include <iostream>
#include <cmath>  
#include "myEigenFunctions.h"

using namespace std;

int main (void) {

	int n = 3; 

	double *y = NULL;
	y = new double [n];

	double **A = NULL;
	A = new double* [n];

	for(int i = 0; i < n; i++) 
		A[i] = new double [n];

	y[0] = 1;
	y[1] = 0;
	y[3] = 0;

	A[0][0] = 5; 
	A[0][1] = -2; 
	A[0][2] = 0; 

	A[1][0] = -2; 
	A[1][1] = 3; 
	A[1][2] = -1; 
	
	A[2][0] = 0; 
	A[2][1] = -1; 
	A[2][2] = 1; 

	double delta = 0.0001;
	double lambda = 1;

	eigen_shift(A, y, n, lambda, delta);
	eigen_all(A, y, n, lambda, delta);
	return 0;
}

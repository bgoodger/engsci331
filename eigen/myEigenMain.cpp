/*
	APPLICATION OF EIGEN FUNCTIONS TO SOLVE MASS SYSTEM
	Ben Goodger
	1822049
*/

#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#include "myEigenFunctions.h"
using namespace std;

#define PI 3.14159265358979323846
#define eps 0.00000000000000000000001 

int main(void) 
{
	// Defining local variables to be used:
  
	double *M = new double [n];			// Mass vector
		   *K = new double [n];			// Spring vector

	double **A= new double* [n];		// System Matrix

	double G = 7.929*pow(10.0,10); 		// Shear modulus
	double rho = 7751; 					// Density
	double D = 0.005; 					// Wire diameter
	double R = 0.0532;					// Mean coil radius 
	double Na = 10; 					// number of active coils

 	n =(int) Na;						// number of coils and masses are the same in this discretisation

	for(int i = 0; i < n; i++) 
		A[i] = new double [n];

	// Values given for problem 
	for(int i = 0; i < n; i++)  {
		M[i] = PI*PI*D*D*rho*R/2;
		K[i] = (G*pow(D,4))/(64*pow(R,3));
	}

	K[0] = 2*K[0]; // Correct first value
 
 	// Construct the A matrix
	A[0][0] = ( -K[0] -K[1]) / M[0];

	A[n-1][n-1] = -K[n-1] / M[n-1];
	A[n-1][n-2] = K[n-1] / M[n-1];
	A[n-2][n-1] = K[n-1] / M[n-2];

	for(int i = 1; i < n-1; i++) {
		A[i][i] = (-K[i] -K[i+1]) / M[i];
		A[i][i-1] = K[i] / M[i];
		A[i-1][i] = K[i] / M[i-1];
	}

	// Allocating/Initial values needed
	double* y = new double [n];
	double lambda = 0;
	double delta = eps;

	cout << "\n" << "Shifting" << "\n";
	eigen_shift (A, y, n, lambda, delta);

	cout << "\n\nAll" << "\n";
	eigen_all (A, y, n, lambda, delta);


	for(int i = 0; i < n; i++) {
		delete [] A[i];
	}

	delete [] A;
	delete [] M;
	delete [] K;

}




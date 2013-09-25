/*
	EIGEN FUNCTION IMPLEMENTATION
	Ben Goodger
	1822049
*/

#include "myEigenFunctions.h"

void eigen_shift (double **A, double *y, int n, double &lambda, double delta) {

	// Calculates the largest and smallest eigen value. 

	double largeLambda; 

	double **B = new double* [n];
	for(int i = 0; i < n; i++) 
		B[i] = new double [n];

	power_method(A, y, n, lambda, delta);

	cout << "Largest lambda " << " : " << lambda << "\n"; 
	cout << "Natural Frequency " << " : " << sqrt(lambda)/(2*PI) << "\n"; 
	cout << "y"  << ":\n";
	for(int i = 0; i < n; i++) 
		cout << y[i] << "  "; 

	largeLambda = lambda; // Store it for later

	// Shift matrix 
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			B[i][j] = A[i][j] -  ((i==j)? largeLambda : 0);
		}
	}

	cout << "\n";

	power_method(B, y, n, lambda, delta);

	// Lambda is transformed back to the original solution space
	cout << "\nsmallest lambda " << " : " << (largeLambda - lambda) << "\n"; 
	cout << "Natural Frequency " << " : " << sqrt(largeLambda - lambda)/(2*PI)<< "\n"; 
	cout << "y"  << ":\n";
	for(int i = 0; i < n; i++) 
		cout << y[i] << "  "; 

	cout << "\n";

	
	for(int i = 0; i < n; i++) {
		delete [] B[i];
	}

	delete [] B;	
}


void eigen_all (double **A, double *y, int n, double &lambda, double delta) {

	// Prints out all the eigen vectors, values and frequencies

	for(int j = 0; j < n; j++) {
		power_method(A, y, n, lambda, delta);
		cout << "y" << j+1  << ":\n";
		for(int i = 0; i < n; i++) {
			cout << y[i] << "  "; 
		}
		cout << "\n" << "lambda " << j+1 << " : " << lambda << "\n"; 
		cout << "Natural Frequency " << " : " << sqrt(-lambda)/(2*PI) << "\n\n"; 

		A = deflate(A,n,y,lambda);
	}

}

double** deflate (double **A, int n,  double *y, double lambda) {

	// Creates a matrix without the specified eigen value/vector

	double **B = new double* [n];
	for(int i = 0; i < n; i++) 
		B[i] = new double [n];

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			B[i][j] = A[i][j] - lambda*y[i]*y[j];
		}
	}

	return B; // Cant delete, it's needed later

}

void power_method (double **A, double *y, int n, double &lambda, double delta) {

	// Calculates the largest eigen vector and value for a square matrix A
	// The initial y vector is modified in place to be the normalised eigen vector
	// delta is the user defined tolerance
	// A must be a square matrix of dimension n, and y must be n long 

	lambda = Norm(y ,n);
	double lambdaOld;
	double yNew[n];

	// Initial guess for the eigen vector
	for(int i = 0; i < n; i++)
		y[i] = 1/sqrt(n);

	while (true) {

		// A * y 
		for(int i = 0; i < n; i++) {
			yNew[i] = 0;
			for(int j = 0; j < n; j++) {
				yNew[i] += A[i][j] * y[j];
			}
		}

		for(int i = 0; i < n; i++) 
			y[i] = yNew[i];

		lambdaOld = lambda; 
		lambda = Norm(y ,n);

		// The following checks for negative eigen values
		// If it is negative the eigen value needs to be adjusted
		for (int i = 0; i < n; i++) {
			if ((abs(y[i]) > eps) && (abs(yNew[i])>eps)) {
				if (y[i] + yNew[i] < y[i] + yNew[i]) {
					lambda = -1*lambda;
					break;
				}
			}
		} 
		
		// y = y / lambda
		for(int i = 0; i < n; i++) {
			y[i] = y[i] / lambda;
		}

		if ((abs(lambda - lambdaOld) / abs(lambda)) < delta)  {
			// We have converged!
			return;
		}
	}


}

/*
	MATRIX OPERATIONS
*/
double Norm(double *A, int n) {

	// Returns the (pythagorean?) norm of a vector

	return  sqrt(DotProduct(A,A,n));

}

double DotProduct(double *A, double *B, int n) {
	// Dot product of two vectors

	double dot = 0.0;
	for(int i = 0; i < n; i++) {
		dot += A[i]*B[i];
	}
	return dot;

}
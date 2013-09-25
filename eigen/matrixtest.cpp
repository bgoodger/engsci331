
#include <iostream>
#include <cmath>  

void power_method(double **A, double *y, int n, double &lamdba, double delta);
void eigen_all (double **A, double *y, int n, double &lambda, double delta);
double Norm(double *A, int n);
double** deflate (double **A, int n,  double *y, double lambda);
void eigen_shift (double **A, double *y, int n, double &lambda, double delta);

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

	return 0;
}

void eigen_shift (double **A, double *y, int n, double &lambda, double delta) {

	double largeLambda; 

	double **B = new double* [n];
	for(int i = 0; i < n; i++) 
		B[i] = new double [n];

	power_method(A, y, n, lambda, delta);

	std::cout << "biggest lambda " << " : " << lambda << "\n\n"; 
	std::cout << "y"  << ":\n";
	for(int i = 0; i < n; i++) {
		std::cout << y[i] << "\n"; 
	}

	largeLambda = lambda;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			B[i][j] = A[i][j] -  ((i==j)? largeLambda : 0);
			cout << B[i][j] << " ";
		}
	}

	cout << "\n";

	y[0] = 0;
	y[1] = 0.5;
	y[2] = 1;

	power_method(B, y, n, lambda, delta);

	std::cout << "smallest lambda " << " : " << largeLambda - lambda << "\n\n"; 
	std::cout << "y"  << ":\n";
	for(int i = 0; i < n; i++) {
		std::cout << y[i] << "\n"; 
	}
}


void eigen_all (double **A, double *y, int n, double &lambda, double delta) {

	for(int j = 0; j < n; j++) {
		power_method(A, y, n, lambda, delta);
		std::cout << "y" << j+1  << ":\n";
		for(int i = 0; i < n; i++) {
			std::cout << y[i] << "\n"; 
		}
		std::cout << "lambda " << j+1 << " : " << lambda << "\n\n"; 

		A = deflate(A,n,y,lambda);
	}

}

double** deflate (double **A, int n,  double *y, double lambda) {

	double **B = new double* [n];
	for(int i = 0; i < n; i++) 
		B[i] = new double [n];

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			B[i][j] = A[i][j] - lambda*y[i]*y[j];
		}
	}

	return B; 

}

void power_method (double **A, double *y, int n, double &lambda, double delta) {

	// Calculates the largest eigen vector and value for a square matrix A
	// The initial y vector is modified in place to be the normalised eigen vector
	// delta is the user defined tolerance
	// A must be a square matrix of dimension n, and y must be n long 

	lambda = Norm(y ,n);
	double lambdaOld;
	double yNew[n];

	while (true) {

		// A * y 
		for(int i = 0; i < n; i++) {
			yNew[i] = 0;
			for(int j = 0; j < n; j++) {
				yNew[i] += A[i][j] * y[j];
			}
		}

		for(int i = 0; i < n; i++) {
			y[i] = yNew[i];
		}

		lambdaOld = lambda; 
		lambda = Norm(y ,n);

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

double Norm(double *A, int n) {

	// Returns the (pythagorean?) norm of a vector

	double norm = 0.0;

	for(int i = 0; i < n; i++) {
		norm += A[i]*A[i];
	}

	norm = sqrt(norm);

	return norm;
}
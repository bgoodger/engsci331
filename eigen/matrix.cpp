#include "Matrix.h"


//#include <string> 

	// A blank matrix can either be initialised or an exisiting 2D array can be passed in
	Matrix::Matrix(int n, int m) {
		_n = n;
		_m = m;

		mat = new double* [n];
		for(int i = 0; i < n; i++) 
			mat[i] = new double [m];
	}
	Matrix::Matrix(double** matrix) {}
	Matrix::Matrix(std::string fileHandle) {}

	Matrix::~Matrix() {}

	void Matrix::setElement(int n, int m, double value) {
		mat[n-1][m-1] = value;
	}
	double Matrix::getElement(int n, int m) { return mat[n-1][m-1];}

	int Matrix::getM() { return _m; }
	int Matrix::getN() { return _n; }

	std::string Matrix::pretty() {} // Returns a pretty string version of the matrix

	// Operations on self
	double Matrix::determinant() {}
	Matrix Matrix::transpose() {}
	Matrix Matrix::invs() {}
	double Matrix::trace() {}

	// Operations with other matricies

	Matrix Matrix::multiply(Matrix product) {}
	double Matrix::dotProduct(Matrix product) {

		double dot = 0.0;

		assert(product.getN()==_n);
		assert(product.getM()==_m);

		for(int i = 0; i < _n; i++) {
			for (int j = 0; j < _m; j++) {
				dot += Matrix::getElement(i,j) * product.getElement(i,j);
			}
		}

		return dot;
	}

#include "Matrix.h"



	// A blank matrix can either be initialised or an exisiting 2D array can be passed in
	Matrix::Matrix(int m, int n) {}
	Matrix::Matrix(double** matrix){}

	Matrix::~Matrix();

	public void Matrix::setElement(int m, int n, double value);
	public double getElement(int m, int n); 

	string pretty(); // Returns a pretty string version of the matrix

	// Operations on self
	double determinant();
	Matrix transpose();
	Matrix invs();
	double trace();

	// Operations with other matricies

	Matrix multiply(Matrix product);

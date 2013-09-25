/* 
	Interface for Matrix class 

*/

#include <string> 
#include <assert.h>


class Matrix
{
	double** mat; 

	// Number of columns/rows
	int _m; 
	int _n; 

public:

	// A blank matrix can either be initialised or an exisiting 2D array can be passed in
	Matrix(int n, int m);
	Matrix(double** matrix);
	Matrix(std::string fileHandle);

	~Matrix();

	void setElement(int n, int m, double value);
	double getElement(int n, int m); 

	int getN();
	int getM();

	std::string pretty(); // Returns a pretty string version of the matrix

	// Operations on self
	double determinant();
	Matrix transpose();
	Matrix invs();
	double trace();

	// Operations with other matricies
	Matrix multiply(Matrix product);
	double dotProduct(Matrix product);

};
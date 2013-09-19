/* 
	Interface for Matrix class 

*/

#include <string> 

class Matrix
{
	double** mat; 

	// Number of columns/rows
	int m; 
	int n; 

public:

	// A blank matrix can either be initialised or an exisiting 2D array can be passed in
	matrix(int m, int n);
	matrix(double** matrix);

	~matrix();

	void setElement(int m, int n, double value);
	double getElement(int m, int n); 

	string pretty(); // Returns a pretty string version of the matrix

	// Operations on self
	double determinant();
	Matrix transpose();
	Matrix invs();
	double trace();

	// Operations with other matricies

	Matrix multiply(Matrix product);

};
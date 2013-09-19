/* 
	Interface for Matrix class 

*/

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

	// Operations on self
	void determinant();
	void transpose();
	void invs();
	void trace();

	// Operations with other matricies

	Matrix multiply(Matrix product);

};
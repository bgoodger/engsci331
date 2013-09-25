/*
	EIGEN FUNCTION HEADER FILE
	Ben Goodger
	1822049
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#define PI 3.14159265358979323846
#define eps 0.00000000000000000000001 

void power_method(double **A, double *y, int n, double &lamdba, double delta);
void eigen_all (double **A, double *y, int n, double &lambda, double delta);
double** deflate (double **A, int n,  double *y, double lambda);
void eigen_shift (double **A, double *y, int n, double &lambda, double delta);

double DotProduct(double *A, double *B, int n);
double Norm(double *A, int n);
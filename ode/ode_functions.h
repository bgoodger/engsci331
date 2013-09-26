
/*
 * ode_functions.h
 * 
 * Functions for calculating derivatives to be integrated using
 * numerical methods for ODEs
 */

#ifndef _ode_functions_h_
#define _ode_functions_h_

// These are the parameters governing the path tracking problem.  They are #defined so that the dydx 
// function list is the same for all functions.  Change them and test your adaptive stepping code.
#define AA 5.0
#define BB 2
#define CC -0.1
#define DD 20
#define EE 3


#define PI 3.1415926535

#include <math.h>

/* Create a derivative function pointer variable type */
typedef void (*derivative_function)(int, double, double*, double *, int &);

/*
 * Derivative information in system form for sample function:
 *   y''+a^2y=0 where a=2
 * Input:
 *   n = size of system
 *   x = current step
 *   y = current approximation, (nx1) array
 * Output:
 *   f = derivative, (nx1) array
 */
void sample_function_derivative(int n, double x, double *y, double *f, int &callCounter);


/*
 * Derivative information in system form for predator-prey function
 */
void predator_prey_derivative(int n, double x, double *y, double *f, int &callCounter);


/*
 * Derivative information in system form for bungy jumper function
 */
void bungy_jumper_derivative(int n, double x, double *y, double *f, int &callCounter);




void path_derivative(int n, double x, double *y, double *f, int &callCounter);

#endif



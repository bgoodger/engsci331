
/*
 * ode_methods.cpp
 *
 * Implementations of the Euler, Improved Euler and classical
 * fourth-order Runge-Kutta methods for solving systems of first-order
 * ODEs
 */

#include <assert.h>
#include <stdlib.h>
#include "ode_methods.h"


/*
 * Euler method for solving a system of first-order ODEs
 * Input:
 *   n = size of system
 *   dydx = first-order system of ODEs
 *   x_initial = initial conditions
 *   y_initial = initial conditions, (nx1) array
 *   number_of_steps = number of steps
 *   step_size = step size
 * Output:
 *   x = solution, (1x(number_of_steps+1)) array
 *   y = solution, (nx(number_of_steps+1)) array stored by column
 */
void euler(int n, derivative_function dydx, double x_initial, double *y_initial, int number_of_steps, double step_size, double *x, double **y, int &callCounter)
{
  int i, k;
  double *f = NULL;

  /* Verify function parameters */
  assert(n > 0);
  assert(dydx);
  assert(y_initial);
  assert(number_of_steps > 0);
  assert(step_size > 0.0);
  assert(x);
  assert(y);
  
  /* Set initial conditions */
  x[0] = x_initial;
  for (i = 0; i < n; i++) {
    y[0][i] = y_initial[i];
  }

  /* Allocate work vector */
  f = new double [n];
  
  /* Iterate using the Euler method */
  for (k = 0; k < number_of_steps; k++) {

    dydx(n, x[k], y[k], f, callCounter);

    for (i = 0; i < n; i++) 
		y[k+1][i] = y[k][i] + step_size*f[i];
  
    x[k+1] = x[k] + step_size;
  }

  /* Free work vector */
  delete [] f;
}


/*
 * Improved Euler method for solving a system of first-order ODEs - YOU DO THIS BIT!
 */
void improved_euler(int n, derivative_function dydx, double x_initial, double *y_initial, int number_of_steps, double step_size, double *x, double **y, int &callCounter)
{

}


/*
 * Classical fourth-order Runge-Kutta method for solving a system of first-order ODEs - YOU DO THIS BIT!
 */
void runge_kutta(int n, derivative_function dydx, double x_initial, double *y_initial, int number_of_steps, double step_size, double *x, double **y, int &callCounter)
{
  
}

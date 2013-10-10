
/*
 * ode_methods.cpp
 *
 * Implementations of the Euler, Improved Euler and classical
 * fourth-order Runge-Kutta methods for solving systems of first-order
 * ODEs
 */

#include <assert.h>
#include <stdlib.h>
 #include <iostream>
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
  int i, k;
  double *f = NULL;
  double *fest = NULL;

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

  /* Allocate work vectors */
  f = new double [n];
  fest = new double [n];
  //fest = new double [n];

  /* Iterate using the Improved-Euler method */
  for (k = 0; k < number_of_steps; k++) {

    dydx(n, x[k], y[k], f, callCounter);

    // Estimated value, will be overwritten on next iteration
    for (i = 0; i < n; i++) 
      y[k+1][i] = y[k][i] + step_size*f[i];

    x[k+1] = x[k] + step_size;

    // Estimated value, will be overwritten on next iteration
    dydx(n, x[k+1], y[k+1], fest, callCounter);
    
    // Overwrite estimate
    for (i = 0; i < n; i++) 
      y[k+1][i] = y[k][i] + (step_size/2) * (f[i] + fest[i]);

  }

  // Free work vector 
  delete [] f;
  delete [] fest;
}


/*
 * Classical fourth-order Runge-Kutta method for solving a system of first-order ODEs - YOU DO THIS BIT!
 */
void runge_kutta(int n, derivative_function dydx, double x_initial, double *y_initial, int number_of_steps, double step_size, double *x, double **y, int &callCounter)
{

  int i, k;

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

  /* Allocate work vectors */
  double* f0 = new double [n];
  double* f1 = new double [n];
  double* f2 = new double [n];
  double* f3 = new double [n];

  /* Iterate using the classical RK4 */
  for (k = 0; k < number_of_steps; k++) {

    x[k+1] = x[k] + step_size;

    dydx(n, x[k], y[k], f0, callCounter);

    for (i = 0; i < n; i++) 
      y[k+1][i] = y[k][i] + 0.5*step_size*f0[i];

    dydx(n, x[k] + (step_size/2), y[k+1], f1, callCounter);

    for (i = 0; i < n; i++) 
      y[k+1][i] = y[k][i] + 0.5*step_size*f1[i];

    dydx(n, x[k] + (step_size/2), y[k+1], f2, callCounter);

    for (i = 0; i < n; i++) 
      y[k+1][i] = y[k][i] + step_size*f2[i];

    dydx(n, x[k+1], y[k+1], f3, callCounter);

    for (i = 0; i < n; i++) 
      y[k+1][i] = y[k][i] + (step_size/6) * (f0[i] + 2*(f1[i] + f2[i]) + f3[i]);

  }
  
    delete [] f0;
    delete [] f1;
    delete [] f2;
    delete [] f3;

}

void dormand_prince(int n, derivative_function dydx, double x_initial, double x_end, double *y_initial, int max_steps, double min_step_size, double max_step_size, double *x, double **y, int &callCounter, int &steps_taken)
{

  int i, k;
  assert(y);

  // Verify function parameters 
  assert(n > 0);
  assert(dydx);
  assert(y_initial);
  assert(max_steps > 0);
  assert(x);

    // Set initial conditions 
  x[0] = x_initial;


  for (i = 0; i < n; i++) {
    y[0][i] = y_initial[i];
  }

  double step_size = min_step_size;
  double error = 0; 
  // Allocate work vectors 
  double* f1 = new double [n];
  double* f2 = new double [n];
  double* f3 = new double [n];
  double* f4 = new double [n];
  double* f5 = new double [n];
  double* f6 = new double [n];
  double* f7 = new double [n];

 
  k=0;

  while (x[k]<x_end) {

  	// Update the step size.
  	// If our step takes us past the end point, make us stop at the end point. 

  	if ((x[k] + step_size) > x_end ) {
  		x[k+1] = x_end;
  		step_size = fabs(x[k+1] - x[k]);
  	} else {
    	x[k+1] = x[k] + step_size;
    }

    // Calculate the various co-effients and upate Y as we go

    dydx(n, x[k], y[k], f1, callCounter);

    for (i = 0; i < n; i++) 
      y[k+1][i] = y[k][i] + 0.2*step_size*f1[i];

	dydx(n, x[k] + (0.2*step_size), y[k+1], f2, callCounter);
    for (i = 0; i < n; i++) 
      y[k+1][i] = y[k][i] + (3.0/40)*step_size*f1[i] + (9.0/40)*step_size*f2[i];

 	dydx(n, x[k] + ((3.0/10)*step_size), y[k+1], f3, callCounter);
 	for (i = 0; i < n; i++) 
      y[k+1][i] = y[k][i] + (44.0/45)*step_size*f1[i] - (56/15)*step_size*f2[i] + (32.0/9)*step_size*f3[i];

  	dydx(n, x[k] + (0.8*step_size), y[k+1], f4, callCounter);
 	for (i = 0; i < n; i++) 
      y[k+1][i] = y[k][i] + (19372.0/6561)*step_size*f1[i] - (25360.0/2187)*step_size*f2[i] + (64448.0/6561)*step_size*f3[i] - (212.0/729)*step_size*f4[i]; 

   	dydx(n, x[k] + ((8.0/9)*step_size), y[k+1], f5, callCounter);
 	for (i = 0; i < n; i++) 
      y[k+1][i] = y[k][i] + (9017.0/3168)*step_size*f1[i] - (355.0/33)*step_size*f2[i] - (46732.0/5247)*step_size*f3[i] + (49.0/176)*step_size*f4[i] - (5103.0/18656)*step_size*f5[i]; 

 	dydx(n, x[k+1], y[k+1], f6, callCounter);
 	for (i = 0; i < n; i++) 
      y[k+1][i] = y[k][i] + (35.0/384)*step_size*f1[i] + (500.0/1113)*step_size*f3[i] + (125.0/192)*step_size*f4[i] - (2187.0/6784)*step_size*f5[i]  + (11.0/84)*step_size*f6[i]; 

   	dydx(n, x[k+1], y[k+1], f7, callCounter);

   	i=0; // Adjust so the error works
   	error = fabs((71.0/57600)*step_size*f1[i] - (71.0/16695)*step_size*f3[i] + (71.0/1920)*step_size*f4[i] - (17253.0/339200)*step_size*f5[i]  + (22.0/525)*step_size*f6[i] - (1.0/40)*step_size*f7[i]);

   	step_size = step_size*pow((EPS*step_size)/(2*error),(1.0/5));
 	
   	cout << step_size << " " << endl;


   	// Ensure our steps stay within our range to keep our solution accurate
   	if (step_size < min_step_size) {
   		step_size = min_step_size;
   	} else if (step_size > max_step_size) {
   		step_size = max_step_size;
   	} 

 	k++;
 
  }

  	// Return number of results used.
  	steps_taken = k;

    delete [] f1;
    delete [] f2;
    delete [] f3;
    delete [] f4;
    delete [] f5;
    delete [] f6;
    delete [] f7;

}



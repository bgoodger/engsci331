
/*
 * ode_methods.h
 *
 * Implementations of the Euler, Improved Euler and classical
 * fourth-order Runge Kutta methods for solving systems of first-order
 * ODEs
 */

#ifndef _ode_methods_h_
#define _ode_methods_h_

#include "ode_functions.h"

#include <math.h>

#define EPS 1e-6
using namespace std;


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
void euler(int n, derivative_function dydx, double x_initial, double y_initial[], int number_of_steps, double step_size, double *x, double **y, int &callCounter);


/*
 * Improved Euler method for solving a system of first-order ODEs
 * Input:
 *   n = size of system
 *   dydx = first-order system of ODEs
 *   x_initial = initial conditions
 *   y_initial = initial conditions, (nx1) array
 *   number_of_steps = number of steps
 *   step_size = step size
 * Output:
 *   x = solution
 *   y = solution, (nx(number_of_steps+1)) array stored by column
 */
void improved_euler(int n, derivative_function dydx, double x_initial, double *y_initial, int number_of_steps, double step_size, double *x, double **y, int &callCounter);


/*
 * Classical fourth-order Runge-Kuta method for solving a system of
 * first-order ODEs
 * Input:
 *   n = size of system
 *   dydx = first-order system of ODEs
 *   x_initial = initial conditions
 *   y_initial = initial conditions, (nx1) array
 *   number_of_steps = number of steps
 *   step_size = step size
 * Output:
 *   x = solution
 *   y = solution, (nx(number_of_steps+1)) array stored by column
 */
void runge_kutta(int n, derivative_function dydx, double x_initial, double *y_initial, int number_of_steps, double step_size, double *x, double **y, int &callCounter);

void dormand_prince(int n, derivative_function dydx, double x_initial, double x_end, double *y_initial, int max_steps, double min_step_size, double max_step_size, double *x, double **y, int &callCounter, int &steps_taken);
#endif

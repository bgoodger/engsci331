
/*
 * ode_functions.c
 * 
 * Functions for calculating derivatives to be integrated using
 * numerical methods for ODEs
 */

#include <assert.h>
#include <math.h>
#include <iostream>
#include "ode_functions.h"
#include "ode_crypt.h"
using namespace std;

/*
 * Derivative information in system form for sample function:
 *   y''+a^2y=0
 * Input:
 *   n = size of system
 *   x = current step
 *   y = current approximation, (nx1) array
 * Output:
 *   f = derivative, (nx1) array
 */

void sample_function_derivative(int n, double x, double *y, double *f, int &callCounter)
{
  // Verify function parameters 
  assert(n == 2);
  assert(y);
  assert(f);

  // Evaluate derivatives
  f[0] = y[1];
  f[1] = -4 * y[0];

  // Update the counter of dydx function calls:
  callCounter++;
}


/*
 * Derivative information in system form for predator-prey function - YOU DO THIS BIT!
 */
void predator_prey_derivative(int n, double x, double *y, double *f, int &callCounter)
{

  // Verify function parameters 
  assert(n == 2);
  assert(y);
  assert(f);

  double a = 1.2; 
  double b = 0.6;
  double c = 0.8; 
  double d = 0.3; 

  f[0] = (a*y[0]) - (b*y[0]*y[1]); 
  f[1] = (-1*c*y[1]) + (d*y[0]*y[1]); 

  // Update the counter of dydx function calls:
  callCounter++;
}


/*
 * Derivative information in system form for bungy jumper function - YOU DO THIS BIT!
 */

void bungy_jumper_derivative(int n, double x, double *y, double *f, int &callCounter)
{

  // Verify function parameters 
  assert(n == 2);
  assert(y);
  assert(f);

  f[0] = y[1];

  double L = 30;
  double Cd = 0.25;
  double k = 40; 
  double gamma = 8;
  double m = 68.1;
  double g = 9.81;
  
  if (y[0] < L) { // free fall
    f[1] = g - (((y[0] > 0) - (y[0] < 0)) * (Cd * y[1] * y[1]) / m);
  } else { // bungy is taught 
    f[1] = g - (((y[0] > 0) - (y[0] < 0)) * (Cd * y[1] * y[1]) / m) - ((k/m)*(y[0]-L)) - ((gamma/m)*y[1]);
  }

}


/*
	Obfuscated code for the orienteering problem.  Don't worry about how this works - for a given x and y set 
	it will return the 	derivative and update the dydx function call counter just as the sample derivative code does.
*/
void path_derivative(int n, double x, double *y, double *f, int &c)
{
	dkownob dkojewoq,dlowneonb,dkownovw,dpqntobqow;dkojewoq=0.5-0.5*kdowqpyj(oqkrbyoo*slpejyet);dlowneonb=(-ldpwj40y*kdowqnqi*oqkrbyoo/50)*sljwp4jt(kdowqnqi*oqkrbyoo*slpejyet)+dmowqent(loejtpne*(2*oqkrbyoo-oqkrbyoo*slpejyet))*((dkworypq*oqkrbyoo/50)*kdowqpyj(dkworypq*oqkrbyoo*slpejyet)-(loejtpne*oqkrbyoo/50)*sljwp4jt(dkworypq*oqkrbyoo*slpejyet));dkownovw=(oqkrbyoo/100)*sljwp4jt(oqkrbyoo*slpejyet);dpqntobqow=ldpwj40y*kdowqpyj(kdowqnqi*oqkrbyoo*slpejyet)+sljwp4jt(dkworypq*oqkrbyoo*slpejyet)*dmowqent(loejtpne*(2*oqkrbyoo-oqkrbyoo*slpejyet));dlpwjyte=dkojewoq*dlowneonb+dkownovw*dpqntobqow;c++;
} 

// Minimisation methods
#include "mini.h"
#include "math.h"
#include <iostream>

#define A 0
#define B 4
#define C 1
#define D 0-3
#define E 0

#define AA 5
#define BB 100
#define CC -1.5
#define DD 0
#define EE 0

#define RESPHI (2 - (1 + sqrt(5)) / 2)

using namespace std; 

double uniform (eval_function testFunction, double leftBound, double rightBound, double tol, int K, int &callCounter) {

	double x, y, yMin, xMin,dy,ddy,step; 

 	step = fabs(rightBound-leftBound)/(K-1); 
 	x = leftBound; // Set initial value
 
 	for (int i=0; i<K; i++){
 		// Evaluate function, store if minimum value 
 		testFunction(x, y, dy, ddy);
 		callCounter++;
 		if (y < yMin) {
 			yMin = y;
 			xMin = x; 
 		} 
 		x += step; 
 	}

 	leftBound = xMin - step;
 	rightBound = xMin + step;
 	
 	// Recursive step
 	if(fabs(rightBound-leftBound) < tol) {
 		return xMin;
 	} else { 
 		return uniform(testFunction , leftBound, rightBound, tol, K, callCounter); 
 	}
}

double goldenSection (eval_function testFunction, double leftBound, double centrePoint, double rightBound, double tol, int &callCounter) {
	
    double x,yx,yCenter,dy,ddy;	

    if ((rightBound - centrePoint) > (centrePoint - leftBound)){
      x = centrePoint + ( RESPHI * (rightBound - centrePoint));
    } else{
      x = centrePoint - (RESPHI * (centrePoint - leftBound));
    }

    if (fabs(rightBound - leftBound) < tol * (fabs(centrePoint) + fabs(x))) {
      return (rightBound + leftBound) / 2; // We have converged 
    }

    testFunction(x, yx, dy, ddy);
    callCounter++;
    testFunction(centrePoint,yCenter, dy,ddy);
    callCounter++;

    if (yx < yCenter) {
      if (rightBound - centrePoint > centrePoint - leftBound) {
      	return goldenSection(testFunction,centrePoint, x, rightBound, tol,callCounter);
      } else {
      	return goldenSection(testFunction,leftBound, x, centrePoint, tol,callCounter);
      }
    } else {
      if (rightBound - centrePoint > centrePoint - leftBound) {
      	return goldenSection(testFunction,leftBound, centrePoint, x, tol,callCounter);
      } else {
      	return goldenSection(testFunction,x, centrePoint, rightBound, tol,callCounter);
      }
    }

}

double newtonsMethod (eval_function testFunction, double x, double tol, int &callCounter) {
	
	double y,dy,ddy,step;

	testFunction(x, y, dy, ddy);
	callCounter+= 3;
	step = -1 * (dy/ddy);	

	while(step > tol) {
		testFunction(x, y, dy, ddy);
		callCounter+= 3;
		step = -1 * (dy/ddy);
		x += step;
	}

	return x; 
}
// Functions for the test problems

void quartic(double x0, double &f, double &df, double &ddf) {

	f = A*pow(x0,4) + B*pow(x0,3) + C*pow(x0,2) + D*x0 + E;
    df = 4*A*pow(x0,3) + 3*B*pow(x0,2) + 2*C*x0 + D;
	ddf = 3*A*pow(x0,2) + 6*B*x0 + 2*C;
}

void exponential(double x0, double &f, double &df, double &ddf) {

	f = AA - BB*exp(CC*pow(x0,2) + DD*x0 + EE);
	df = -BB*(CC*x0 + DD)*exp(CC*pow(x0,2) + DD*x0 + EE);
	ddf = -BB*(CC*x0 + DD)*(CC*x0 + DD)*exp(CC*pow(x0,2) + DD*x0 + EE);

}


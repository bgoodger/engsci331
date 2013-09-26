
/*
 * ode_main.c
 *
 * This program solves a system of first-order ODEs with initial
 * conditions using the Euler, Improved Euler and classical
 * fourth-order Runge-Kutta methods.
 */

#define _CRT_SECURE_NO_DEPRECATE

#include <math.h>
#include <iostream>
#include <fstream>

#include "ode_methods.h"
#include "ode_functions.h"
#include "ode_score.h"

using namespace std;

int main(void)
{

  int functionNumber,
	  n,
	  i, 
	  k,
	  numSteps=0,
	  s=0, 
	  callCounter=0,
	  myScore=0;

  double x_initial = 0,
		 step_size = 0;
	  
  double *y_initial = NULL,
		 *x = NULL;

  double **yEuler = NULL,
		 **yImprovedEuler = NULL,
		 **yRungeKutta = NULL;

  derivative_function dydx = NULL;
  string functionInfo;

  ofstream results[2];

  //
  //	SETUP SECTION:
  //

  // Read in the problem parameters 
  cout << "Enter the function number: ";
  cin >> functionNumber;
  cout << endl;

  switch (functionNumber) {
    // Sample function 
  case 1:
    dydx = sample_function_derivative;
    n = 2;
    cout << "d2ydx2+a^2y = 0 where a = 2"<<endl;
	functionInfo = "d2ydx2+a^2y = 0 where a = 2";
    break;

    // Predator-prey 
  case 2:
	// YOU HAVE TO WRITE THIS!
    cout << " predator-prey model - YOU HAVE TO WRITE THIS! Press any key to exit."<<endl;
	cin >> n;
	exit(1);
	
    break;

    // Bungy jumper 
  case 3:
    // YOU HAVE TO WRITE THIS!
	cout << "bungy jumper problem - YOU HAVE TO WRITE THIS! Press any key to exit."<<endl;
	cin >> n;
	exit(1);
    break;

    // Orienteering problem 
   case 4:
	// YOU HAVE TO WRITE THIS!
    cout << "Orienteering problem - YOU HAVE TO WRITE THIS! Press any key to exit."<<endl;
	cin >> n;
	exit(1);
    break;

  default:
    cout << "ERROR - Unknown function number! Press any key to exit."<<endl;
	cin >> n;
	exit(1);
	break;
  }
  
  // Allocate memory for initial conditions 
  y_initial = new double [n];

  cout << "Enter the initial condition for x: ";
  cin >> x_initial;
  cout << endl;

  cout << "Enter the "<<n<<" initial condition(s) for y: ";
  for (i = 0; i < n; i++) {
    cin >> y_initial[i];
  }
  cout << endl;

  // Read in the method parameters 
  cout << "Enter the step size: ";
  cin >> step_size;
  cout << endl;

  cout << "Enter the number of steps: ";
  cin >> numSteps;
  cout << endl;

  // Output problem parameters 
  cout << "Function number = "<< functionNumber <<endl;
  cout << "System order = "<< n <<endl;
  cout << "Initial conditions y( "<< x_initial <<" ) = (";
  for (i = 0; i < n; i++) {
    cout <<  y_initial[i] <<", ";
  }
  cout << ")" <<endl<<endl;

  // Output method parameters 
  cout << "Step size = "<<step_size<<endl;
  cout << "Number of steps = "<< numSteps<<endl<<endl;
  
  // Allocate memory for arrays 
  x = new double [numSteps+1];
  yEuler = new double* [numSteps+1];
  yImprovedEuler = new double* [numSteps+1];
  yRungeKutta = new double* [numSteps+1];
 
  for(i = 0; i <= numSteps; i++) {
	  yEuler[i] = new double [n];
	  yImprovedEuler[i] = new double [n];
	  yRungeKutta[i] = new double [n];
  }

  //
  //	SOLUTION SECTION:
  //

  // Test Euler method 
  euler(n, dydx, x_initial, y_initial, 1, step_size, x, yEuler, callCounter);
  cout << "Single Euler step: y( "<< x_initial + step_size <<" ) = ( ";
  for (i = 0; i < n; i++) {
    cout << yEuler[0][i] <<" ";
  }
  cout << ")"<<endl<<endl;

  // Integrate using Euler method 
  euler(n, dydx, x_initial, y_initial, numSteps, step_size, x, yEuler, callCounter);


  //
  //	OUTPUT SECTION:
  //

  // Open files for outputting results 
  results[0].open("odeResults.txt");
  results[1].open("odeResults.m");
   
 // Output results in a table to screen, file, and MATLAB 
  	switch(functionNumber) {
	  case 1:
	  case 2: 
	  case 3:

	  results[1] << "%% ";
	  for (s = 0; s < 2; s++) {
		results[s] << "k\tx\t";
		for (i = 0; i < n; i++) {
		  results[s] << "yEuler("<<i+1<<")\t";
		  results[s] << "yIEuler("<<i+1<<")\t";
		  results[s] << "yRKutta("<<i+1<<")\t";
		}
		if (functionNumber == 1) {
		  results[s] << "yAnalytic\t";
		}
		results[s] << endl;
	  }

	  results[1] << "ode_data=["<<endl;

	  for (s = 0; s < 2; s++) {
		for (k = 0; k <= numSteps; k++) {
		  results[s] << k <<"\t"<< x[k] <<"\t";
		  for (i = 0; i < n; i++) {
			results[s] << yEuler[k][i] << "\t" ;
			results[s] << yImprovedEuler[k][i]<< "\t" ;
			results[s] << yRungeKutta[k][i]<< "\t";
		  }
		  if (functionNumber == 1) {
			results[s] << sin(2.0 * x[k]) / 2.0 << "\t";
		  }
		  results[s] <<endl;
		}
	  }

	  results[1] << "];"<<endl;
		results[1] << "figure(1);"<<endl;
		results[1] << "plot(";
		results[1] << "ode_data(:,2),ode_data(:,3)";
		results[1] << ",ode_data(:,2),ode_data(:,4)";
		results[1] << ",ode_data(:,2),ode_data(:,5)";

		switch (functionNumber) {
			case 1:
				results[1] << ",ode_data(:,2),ode_data(:,"<<3*n+3<<"));"<<endl;
				results[1] << "legend('yEuler','yIEuler','yRKutta','yAnalytic','Location','Best');"<<endl;
				break;
			case 2:
			case 3:
				results[1] << ");"<<endl;
				results[1] <<"legend('yEuler','yIEuler','yRKutta','Location','Best');"<<endl;
				break;
		}
		results[1] << "xlabel('x');"<<endl;
		results[1] << "ylabel('y');"<<endl;
		results[1] << "title({'Solution to " << functionInfo.c_str() <<"', 'y("<<x_initial<<")=( ";
		for(i = 0; i < n; i++) {
			results[1] << y_initial[i]<<" ";
		}
		results[1] << ")', 'h="<<step_size<<", n="<<numSteps<<"'});"<<endl;
    
		results[1] << "figure(2);"<<endl;
		results[1] << "plot(";


		switch(functionNumber) {
			case 1:
				results[1] << "ode_data(:,2),ode_data(:,3)-ode_data(:,"<<3*n+3<<")";
				results[1] << ",ode_data(:,2),ode_data(:,4)-ode_data(:,"<<3*n+3<<")";
				results[1] << ",ode_data(:,2),ode_data(:,5)-ode_data(:,"<<3*n+3<<"));"<<endl;
			break;
			case 2: 
			case 3:
				results[1] << "ode_data(:,2),ode_data(:,6)";
				results[1] << ",ode_data(:,2),ode_data(:,7)";
				results[1] << ",ode_data(:,2),ode_data(:,8));"<<endl;
				break;	
		}

		results[1] << "legend('Euler','IEuler','RKutta','Location','Best');"<<endl;
		results[1] << "xlabel('x');"<<endl;

		switch(functionNumber) {
		case 1:
			results[1] << "ylabel('Error');"<<endl;
			results[1] << "title({'Error in solution to "<<functionInfo.c_str()<<"', 'y("<<x_initial<<")=( ";
			break;
		case 2:
			results[1] << "ylabel('y');"<<endl;
			results[1] << "title({'y2 solution for "<<functionInfo.c_str()<<"', 'y("<<x_initial<<")=( ";
			break;
		case 3: 
			results[1] << "ylabel('v');"<<endl;
			results[1] << "title({'Velocity of "<<functionInfo.c_str()<<"', 'y("<<x_initial<<")=( ";
			break;
		}
	
		for(i = 0; i < n; i++) {
			results[1] << y_initial[i]<<" ";
		}
		results[1] << ")', 'h="<<step_size<<", n="<<numSteps<<"'});"<<endl;

		switch(functionNumber) {
		case 1:
			break;
		case 2:
		case 3:
			results[1] << "figure(3);\n";
			results[1] << "plot(";
			results[1] << "ode_data(:,3),ode_data(:,6)";
			results[1] << ",ode_data(:,4),ode_data(:,7)";
			results[1] << ",ode_data(:,5),ode_data(:,8));"<<endl;
			results[1] << "legend('yEuler','yIEuler','yRKutta','Location','Best');"<<endl;
			results[1] << "xlabel('y1')"<<endl;
			results[1] << "ylabel('y2')"<<endl;
			results[1] << "title({'Phase plot for "<<functionInfo.c_str()<<"', 'y("<<x_initial<<")=( ";
			for(i = 0; i < n; i++) {
				results[1] << y_initial[i]<<" ";
			}
			results[1] << ")', 'h="<<step_size<<", n="<<numSteps<<"'});"<<endl;
			break;
		}
		break;
	case 4:
		// Plotting the results of the orienteering problem:
		results[1] << "%% ";
		for (s = 0; s < 2; s++) {
			results[s] << "k\tx\t";
			for (i = 0; i < n; i++) {
				results[s] << "xAdaptive("<<i+1<<")\t";
				results[s] << "yAdaptive("<<i+1<<")\t";
			}	
			results[s] << endl;
		}

		results[1] << "ode_data=["<<endl;

		for (s = 0; s < 2; s++) {
			for (k = 0; k <= numSteps; k++) {
				results[s] << k <<"\t"<< x[k] <<"\t";
				for (i = 0; i < n; i++) {
					results[s] << yEuler[k][i] << "\t" ;
				}
				results[s] <<endl;
			}
		}

		results[1] << "];"<<endl;
		results[1] << "figure(1);"<<endl;
		results[1] << "polar(ode_data(:,2)*pi()/50,ode_data(:,3));"<<endl;
		results[1] << "title({'Path as tracked by adaptive algorithm, y=f("<<AA<<","<<BB<<","<<CC<<","<<DD<<","<<EE<<"). Final score of "<<myScore<<"'});"<<endl;

		break;
	}
	
  results[0].close();
  results[1].close();
  
  // Free allocated memory 
  delete [] y_initial;
  delete [] x;
  for(i=0; i<numSteps+1;i++) {
	  delete [] yEuler[i];
	  delete [] yImprovedEuler[i];
	  delete [] yRungeKutta[i];
  }

  return 0;
}

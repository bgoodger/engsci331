#include "mini.h"
#include <iostream>

using namespace std;

int  main () {

	int callCounter=0;

	cout << "Quartic functions: " << endl;
	cout << "Uniform: "<< endl;
	cout <<  uniform(quartic, -5,5,0.0000001,100,callCounter);
	cout << "  Number of calls:  " << callCounter << endl <<endl;
	
	callCounter=0;
	cout << "Golden Section: "<< endl;
	cout <<  goldenSection(quartic, -5, 1,5,0.0000001,callCounter);
	cout << "  Number of calls:  " << callCounter << endl << endl;

	callCounter=0;
	cout << "Newton's: "<< endl;      
	cout <<  newtonsMethod (quartic, -5, 0.0000001,callCounter);
	cout << "  Number of calls:  " << callCounter << endl << endl;

	callCounter=0;
	cout << "Exponential functions: " << endl;
	cout << "Uniform: "<< endl;
	cout <<  uniform(exponential, -0.5,2,0.0000001,100,callCounter);
	cout << "  Number of calls:  " << callCounter << endl <<endl;

	callCounter=0;
	cout << "Golden Section: "<< endl;
	cout <<  goldenSection(exponential, -.5, 1,2,0.0000001,callCounter);
	cout << "  Number of calls:  " << callCounter << endl << endl;
  
	callCounter=0;
	cout << "Newton's: "<< endl;
	cout <<  newtonsMethod (exponential, 1, 0.0000001,callCounter);
	cout << "  Number of calls:  " << callCounter << endl << endl;


 	return 0; 

 }
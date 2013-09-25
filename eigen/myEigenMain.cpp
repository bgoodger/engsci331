
/******************************************************************************************************

	This is a template main file for the ENGSCI331 Eigenvectors module.  It demonstrates some new C++ 
	syntax and functions, as described in the accompanying document ENGSCI331_Eigenstuff.pdf.  

	*** There are some examples of "bad" programming in here (bits missing etc) that you will need to 
	find and fix, though this file should compile without errors straight away. ***

	You should use this file to get you started on the assignment.  You're welcome to change whatever
	you'd like to as you go, this is only a starting point.
	
======================================================================================================*/

#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <fstream>
#include <string>

// This is the header file for your functions.  Usual programming practise would be to use a *.cpp 
// file that has the same name (ie: myEigenFunctions.cpp) and include it as normal in your project.
// Inside this file you'll see some ideas for functions that you could use during this project.  I 
// suggest you plan out your code first to see what kind of functions you'll use repeatedly and then
// write them.  
#include "myEigenFunctions.h"
using namespace std;

#define PI 3.14159265358979323846

int main(void) 
{
	// ----------------------------------------------------------------------------------------------
	//
	// PART 1: Initialisation
	//
	// ----------------------------------------------------------------------------------------------
	
	// Defining local variables to be used:

	int n = 0,						// n is the dimensions of the matrix, will be square for the eigen problems
		option = 0;					// the option whether to read the matrix from a file or to construct from 
									// user-entered values of k and m
  
	double *M = NULL,
		   *K = NULL;

	double **A = NULL;

	ifstream infile;
	ofstream outfile;
	string filename;

	// Prompt and read number of masses in system 
	cout <<" Enter the number of masses in system: ";
	cin >> n;
	cout << endl;
  
	// Allocating memory for the 1D arrays - these are the number of masses, n, long:
	M = new double [n];
	K = new double [n];

	// Allocating memory for the 2D arrays - these have dimensions of n*n:
	A = new double* [n];
	for(int i = 0; i < n; i++) 
		A[i] = new double [n];





	// ------------------------------------------------------------------------------------------------
	//
	// PART 2: Populating matrices from user variables OR from a file
	//
	// ------------------------------------------------------------------------------------------------
    
	cout << "Would you like to read the matrix from a file (option 1) or construct a spring/mass system (option 2)?:";
	cin >> option;
	cout << endl;

	switch(option) {
		case 1:

			// Reading in the A matrix from a file
			//
			//				You get to do this bit!
			//
			
			break;
		case 2:
			// Read masses and then spring constants from the user entry:
			//
			//				You get to do this bit!
			//
			// Constructing the A matrix from these values of k and m:
			//
			//				You get to do this bit!
			//
			break;
		default:
			cout << "ERROR: Option "<<option<<" is unrecognised. Please start again and enter 1 or 2."<<endl;
			break;
	}

	// -----------------------------------------------------------------------------------------------
	//
	//	PART 3: Solving the eigen problem
	//
	// -----------------------------------------------------------------------------------------------

	

	// -----------------------------------------------------------------------------------------------
	//
	//	PART 4: Displaying/writing the results
	//
	// -----------------------------------------------------------------------------------------------



	// -----------------------------------------------------------------------------------------------
	//
	//	PART 5: Housekeeping
	//
	// -----------------------------------------------------------------------------------------------

	for(int i = 0; i < n; i++) {
		delete [] A[i];
	}
	delete [] A;

	cout << "I'm finished!"<<endl;
}


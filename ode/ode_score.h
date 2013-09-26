
/*
 * score.h
 * 
 *	Function for calculating score for second part of ODE project.  Details are in the project handout.
 */

#ifndef _score_h_
#define _score_h_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <iostream>
using namespace std;


#define PI 3.1415926535

int GetScore(int n, double *t, double *r, double tol, int m, double a, double b, double c, double d, double e);
int GetFinalScore(int n, double *t, double *r, double tol, int m);

int GetScore(int n, double *t, double **r, double tol, int m, double a, double b, double c, double d, double e);
int GetFinalScore(int n, double *t, double **r, double tol, int m);

#endif
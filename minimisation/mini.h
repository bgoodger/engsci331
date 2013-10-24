
#ifndef mini_h
#define mini_h

typedef void (*eval_function) (double, double&, double&, double&);

double uniform (eval_function testFunction , double leftBound, double rightBound, double tolerance, int K, int &callCounter);
double goldenSection (eval_function testFunction, double leftBound, double centrePoint, double rightBound, double tol, int &callCounter);
double newtonsMethod (eval_function testFunction, double x, double tol, int &callCounter);

void quartic (double x0, double &x, double &dx, double &ddx);
void exponential (double x0, double &x, double &dx, double &ddx);

#endif
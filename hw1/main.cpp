#include <cstdio>
#include <cassert>
#include "equation_solver.h"

enum {
	E_INPUT
};

//------------------------------------------------------------------------------
//! Get input from stdin, read coefficients for square equation
//!
//! @param [out]  a reference to a-coefficient
//! @param [out]  b reference to b-coefficient
//! @param [out]  c reference to c-coefficient
//!
//! @return void
//------------------------------------------------------------------------------

void getInput(double* a, double* b, double* c) {
	assert(a && b && c);
	printf("Enter a, b, c\n");
	if (scanf("%lf %lf %lf", a, b, c) != 3) {
		printf("Wrong input\n");
		exit(E_INPUT);
	}
}

//------------------------------------------------------------------------------
//! Output roots for equation
//!
//! @param [in]  roots_cnt number of roots
//! @param [in]  x1 		first root
//! @param [in]  x2 		second root
//!
//! @return void
//------------------------------------------------------------------------------

void output(int roots_cnt, double x1, double x2) {
	if (roots_cnt == 0) {
		printf("There are no roots\n");
	} else if (roots_cnt == 1) {
		printf("There is 1 root: %f\n", x1);
	} else if (roots_cnt == 2) {
		printf("There are 2 roots: %f and %f\n", x1, x2);
	} else {
		printf("Any number\n");
	}
}

int main() {
	double a, b, c;
	getInput(&a, &b, &c);
	double x1, x2;
	int roots_cnt = solveSquare(a, b, c, &x1, &x2);
	output(roots_cnt, x1, x2);
	return 0;
}
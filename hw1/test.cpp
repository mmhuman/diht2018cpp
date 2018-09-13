#include <cassert>
#include "equation_solver.h"

//------------------------------------------------------------------------------
//! Test solveSquare test_cnt times
//!
//! @return void
//------------------------------------------------------------------------------

void test() {
	const int test_cnt = 1000000;
	const double eps = 1e-5;
	for (int test_num = 0; test_num < test_cnt; ++test_num) {
		double x1, x2;
		double a = rand(), b = rand(), c = rand();
		int result = solveSquare(a, b, c, x1, x2);
		if (result >= 1 && result <= 2) {
			assert(std::abs(a * x1 * x1 + b * x1 + c) <= eps &&
				std::abs(a * x2 * x2 + b * x2 + c) <= eps);
		}
	}
}

int main() {
	test();
	return 0;
}

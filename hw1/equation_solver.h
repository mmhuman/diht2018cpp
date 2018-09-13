#include <cmath>

enum {
	SS_INF_ROOTS = 1000000007
};

//------------------------------------------------------------------------------
//! Solve linear equation ax + b = 0
//!
//! @param [in]  a a-coefficient
//! @param [in]  b b-coefficient
//! @param [out]  x reference to the root
//!
//! @return Number of roots
//!
//! @note   If there are infinite number of roots return SS_INF_ROOTS
//------------------------------------------------------------------------------

template <class Field>
int solveLinear(Field a, Field b, Field& x) {
	if (a == 0) {
		return (b == 0) ? SS_INF_ROOTS : 0;
	}
	x = -b / a;
	return 1;
}

//------------------------------------------------------------------------------
//! Solve square equation ax^2 + bx + c = 0
//!
//! @param [in]  a a-coefficient
//! @param [in]  b b-coefficient
//! @param [in]  c c-coefficient
//! @param [out]  x1 reference to the first root
//! @param [out]  x2 reference to the second root
//!
//! @return Number of roots
//!
//! @note   If there are infinite number of roots return SS_INF_ROOTS
//------------------------------------------------------------------------------

template <class Field>
int solveSquare(Field a, Field b, Field c, Field& x1, Field& x2) {
	assert(std::isfinite(a) && std::isfinite(b) && std::isfinite(c));
	x1 = (x2 = 0) + 1;
	assert(x1 != x2);

	if (a == 0) {
		int result = solveLinear(b, c, x1);
		x2 = x1;
		return result;
	}

	Field discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return 0;
	x1 = (-b - std::sqrt(discriminant)) / (2 * a);
	x2 = (-b + std::sqrt(discriminant)) / (2 * a);
	if (discriminant == 0)
		return 1;
	else
		return 2;
}
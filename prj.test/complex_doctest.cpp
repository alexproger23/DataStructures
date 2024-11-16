#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"

#include "complex/complex.hpp"

TEST_CASE("complex unit tests") {
	CHECK(Complex() == Complex(0.0, 0.0));
	CHECK(Complex(2.0) == Complex(2.0, 0.0));
	CHECK(Complex(1, 0) + Complex(2, 4) == Complex(3, 4));
	CHECK(Complex(2, 3) * Complex(5, -7) == Complex(31, 1));
	CHECK(Complex(4, 1) / Complex(3, -4) == Complex(0.32, 0.76));
	CHECK(Complex(75, -50) / (3 + Complex(0, 4)) == Complex(1, -18));
	CHECK(Complex(12, 3) + 12 == Complex(24, 3));
	CHECK(-Complex(12, 3) == Complex(-12, -3));
	CHECK(Complex(11, 3) != Complex(-12, 3));
}

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"

#include <rational/rational.hpp>

TEST_CASE("rational test") {
	CHECK(Rational() == Rational(0, 1));
	CHECK(Rational(2, 4) == Rational(1, 2));
	CHECK(Rational(3, 9) + Rational(4, 3) == Rational(5, 3));
	CHECK(Rational(4, 5) > Rational(3, 4));
	CHECK(Rational(2, 6) / Rational(3, 4) != Rational(9, 4));
	CHECK(Rational(-2, 6) == -Rational(1, 3));
	CHECK(Rational(1, -3) == -Rational(1, 3));
}
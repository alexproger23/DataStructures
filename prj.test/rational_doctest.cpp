
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.hpp>

#include <rational/rational.hpp>

TEST_CASE("rational test 1: constuction") {
	CHECK(Rational() == Rational(0, 1));
	CHECK(Rational() == Rational(0));
	CHECK(Rational(1) == Rational(1, 1));
	CHECK(Rational(2, 4) == Rational(1, 2));
	CHECK(Rational(39, 13) == Rational(3));
	CHECK(Rational(Rational(0)) == Rational(0));
}

TEST_CASE("rational test 2: base_operators") {
	CHECK((Rational(2, 4) += Rational(1, 2)) == Rational(1, 1));
	CHECK(Rational(3, 9) + Rational(4, 3) == Rational(5, 3));
	CHECK(Rational(3, 9) + Rational(-4, 3) == Rational(-1));
	CHECK(Rational(2, 6) / Rational(3, 4) == Rational(4, 9));
	CHECK(Rational(2, 6) / Rational(-3, 4) == Rational(-4, 9));
	CHECK(Rational(3, 2) - Rational(1, 2) == Rational(1, 1));
	CHECK(Rational(3, 2) - Rational(43, 7) == Rational(-65, 14));
	CHECK(Rational(5, -4) * Rational(2, 1) == Rational(-5, 2));
	CHECK(Rational(5, 4) * Rational(2, 3) == Rational(5, 6));
	CHECK(Rational(-1, 3) == -Rational(1, 3));
	CHECK(Rational(1, -3) == -Rational(1, 3));
}

TEST_CASE("rational test 3: logic_base_operators") {
	CHECK(Rational(1, 3) > Rational(8, 988));
	CHECK(Rational(1, 2) > Rational(1, 3));
	CHECK(Rational(1, 3) >= Rational(8, 988));
	CHECK(Rational(1, -3) < Rational(1, 3));
	CHECK(Rational(4, 13) < Rational(1, 3));
	CHECK(Rational(1, -3) <= Rational(1, 3));
	CHECK(Rational(1, 3) != Rational(2, 3));
	CHECK(Rational(2, 4) != Rational(2, 3));
	CHECK(Rational(-1, -3) == Rational(1, 3));
}
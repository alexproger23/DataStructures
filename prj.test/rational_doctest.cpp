
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <rational/rational.hpp>

TEST_CASE("testing rational lib") {
	CHECK(Rational() == Rational(0, 1));
}
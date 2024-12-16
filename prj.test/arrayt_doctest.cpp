#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.hpp>

#include "arrayt/arrayt.hpp"

TEST_CASE("arrayd unit tests") {
	CHECK(ArrayT<int>(3).Size() == 3);
}
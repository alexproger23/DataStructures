#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.hpp>

#include "arrayd/arrayd.h"

TEST_CASE("complex unit tests") {
	CHECK(ArrayD(3).Size() == 3);
	CHECK(ArrayD().Size() == 0);
}
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.hpp>

#include <stackl/stackl.hpp>

TEST_CASE("stackl - test") {
	StackL st;
	st.Push(14);
	st.Push(12);
	CHECK(st.Top() == 12);
	st.Pop();
	CHECK(st.Top() == 14);
}
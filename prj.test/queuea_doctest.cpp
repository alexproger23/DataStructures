#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.hpp>

#include "queuea/queuea.hpp"

TEST_CASE("arrayd unit tests") {
	QueueA q;
	q.Push(2);
	CHECK(q.Top() == 2);
}


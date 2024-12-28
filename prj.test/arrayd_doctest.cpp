#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.hpp>

#include "arrayd/arrayd.hpp"

TEST_CASE("arrayd unit tests") {
	CHECK(ArrayD(3).Size() == 3);
	CHECK(ArrayD().Size() == 0);

	ArrayD a(4);
	a[0] = 32;
	a[3] = 2;
	CHECK(a[2] == 0.0);
	CHECK(a[3] == 2);
	CHECK(a.Size() == 4);

	ArrayD b = a;
	CHECK(b[0] - 1 == 31);
	CHECK(b[0] == 32);
	CHECK(b[2] == 0);

	b[3] -= 1;

	CHECK(b[3] == 1);
	CHECK(a[3] == 2);

	b.Resize(5);
	CHECK(b[4] == 0);
	CHECK(b.Size() == 5);
	CHECK(a.Size() == 4);

}

TEST_CASE("[arrayd] - constructors and size") {
    ArrayD a(9);
    CHECK(a.Size() == 9);
    for (ptrdiff_t i = 0; i < a.Size(); i++) {
        CHECK(a[i] == 0.0);
    }
    ArrayD b;
    CHECK(b.Size() == 0);
}

TEST_CASE("[arrayd] - element access and assignment") {
    ArrayD a(3);
    a[0] = 1.11;
    a[1] = 2.12;
    a[2] = 3.13;

    CHECK(a[0] == 1.11);
    CHECK(a[1] == 2.12);
    CHECK(a[2] == 3.13);

    const ArrayD b(a);
    CHECK(b[0] == 1.11);
    CHECK(b[1] == 2.12);
    CHECK(b[2] == 3.13);
}

TEST_CASE("[arrayd] - resize") {
    ArrayD a(3);
    a[0] = 1.0;
    a[1] = 2.0;
    a[2] = 3.0;

    a.Resize(5);
    CHECK(a.Size() == 5);
    CHECK(a[0] == 1.0);
    CHECK(a[1] == 2.0);
    CHECK(a[2] == 3.0);
    CHECK(a[3] == 0.0);
    CHECK(a[4] == 0.0);

    a.Resize(2);
    CHECK(a.Size() == 2);
    CHECK(a[0] == 1.0);
    CHECK(a[1] == 2.0);
}

TEST_CASE("[arrayd] - insert") {
    ArrayD a(3);
    a[0] = 1.0;
    a[1] = 3.0;
    a[2] = 4.0;

    a.Insert(1, 2.0);
    CHECK(a.Size() == 4);
    CHECK(a[0] == 1.0);
    CHECK(a[1] == 2.0);
    CHECK(a[2] == 3.0);
    CHECK(a[3] == 4.0);

    a.Insert(0, 0.0);
    CHECK(a.Size() == 5);
    CHECK(a[0] == 0.0);
    CHECK(a[1] == 1.0);
    CHECK(a[2] == 2.0);
    CHECK(a[3] == 3.0);
    CHECK(a[4] == 4.0);

    a.Insert(5, 5.0);
    CHECK(a.Size() == 6);
    CHECK(a[5] == 5.0);
}

TEST_CASE("[arrayd] - remove") {
    ArrayD a(5);
    for (ptrdiff_t i = 0; i < a.Size(); ++i) {
        a[i] = i + 1;
    }

    a.Remove(2);
    CHECK(a.Size() == 4);
    CHECK(a[0] == 1.0);
    CHECK(a[1] == 2.0);
    CHECK(a[2] == 4.0);
    CHECK(a[3] == 5.0);

    a.Remove(0);
    CHECK(a.Size() == 3);
    CHECK(a[0] == 2.0);
    CHECK(a[1] == 4.0);
    CHECK(a[2] == 5.0);

    a.Remove(2);
    CHECK(a.Size() == 2);
    CHECK(a[0] == 2.0);
    CHECK(a[1] == 4.0);
}

TEST_CASE("[arrayd] - copy constructor and assignment") {
    ArrayD a(3);
    a[0] = 1.0;
    a[1] = 2.0;
    a[2] = 3.0;

    ArrayD b = a;
    CHECK(b.Size() == 3);
    CHECK(b[0] == 1.0);
    CHECK(b[1] == 2.0);
    CHECK(b[2] == 3.0);

    ArrayD c;
    c = a;
    CHECK(c.Size() == 3);
    CHECK(c[0] == 1.0);
    CHECK(c[1] == 2.0);
    CHECK(c[2] == 3.0);
}

TEST_CASE("[arrayd] - edge cases") {
    ArrayD a;
    CHECK(a.Size() == 0);

    ArrayD c(10);
    CHECK_NOTHROW(c[9] = 1.0);
    CHECK_THROWS_AS(c[10] = 2.0, std::out_of_range);
}

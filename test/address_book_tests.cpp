#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

#include "address_book.hpp"

TEST_CASE("entries can be added and removed") {
	address_book ab;
	CHECK_FALSE(ab.has_entry("Jane Doe"));
	ab.add_entry("Jane Doe");
	CHECK(ab.has_entry("Jane Doe"));
	ab.remove_entry("Jane Doe");
	CHECK_FALSE(ab.has_entry("Jane Doe"));
}

TEST_CASE("on wrong insertion expections") {
	address_book ab;
	CHECK_THROWS(ab.add_entry(""));
    std::string myStringA(99, 'a');
    std::string myStringB(101, 'b');
	CHECK_NOTHROW(ab.add_entry(myStringA));
	CHECK_THROWS(ab.add_entry(myStringB));
}

#include <catch.hpp>

unsigned int Factorial(unsigned int number) {
	return number <= 1 ? number : Factorial(number - 1)*number;
}

struct ExampleTestParams
{
	int m_int = -1;
	int m_expected_result = -1;
};

TEST_CASE("Factorials are computed", "[factorial]") {
	auto data = GENERATE(values<ExampleTestParams>({
		{1, 1},
		{2, 2},
		{3, 6},
		{10, 3628800}
		}));

	REQUIRE(Factorial(data.m_int) == data.m_expected_result);
}
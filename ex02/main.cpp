#include <string>
#include <iostream>
#include <cstdlib> // for strtol
#include <vector>
#include <sstream>
#include <cctype> // for
#include "PmergeMe.hpp"
#include "utils.hpp"
#include "group_iterator_tests.hpp"

void runTests()
{
	std::cout << "Running tests" << std::endl;
	PmergeMe merger;
	// Test testVectorSort
	int arr[] = {5, 4, 3, 2, 1};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
	// merger.testVectorSort(vec, true);

	// Test multipleTestVectorSort
	merger.multipleTestVectorSort(10, 100, 1000, false);
}

int main(int argc, char **argv)
{
	std::string input(argv[1]);
	if (argc == 2 && input == "test")
	{
		runTests();
		return 0;
	}
	std::vector<int> numbers;
	if (!checkInputAndFillNumersVec(argc, argv, numbers))
		return 1;

	PmergeMe merger(numbers);
	// TODO I need also a default constructor for when we don't pass any arugment
	// TODO test all the functions.

	return 0;
}

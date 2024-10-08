#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define DEFAULT_PRECISION 8

#include <string>
#include <iostream>
#include <iomanip> // for std::setprecision
#include <sstream>
#include <vector>
#include <deque>
#include <list>
#include <ctime>
#include <cstdlib> // For srand() and rand()

#include "GroupIterator.hpp"

template <typename RandomAccessIterator>
struct PendChainNode
{
	// The iterator pointing to the current element
	RandomAccessIterator it;
	// Iterator to the next element in the main chain
	// next is probably a deceptive name, cause next is not pointing to the next node in the chain
	typename std::list<RandomAccessIterator>::iterator next;
};

class PmergeMe
{
  public:
	PmergeMe();
	PmergeMe(const std::vector<int> &numbers);
	~PmergeMe();

	void sortVec(bool print);
	void sortDeque(bool print);
	void sortVecAndDeque();

	template <typename RandomAccessIterator, typename Compare>
	void mergeInsertionSort(RandomAccessIterator first,
							RandomAccessIterator last,
							Compare compare,
							const std::vector<unsigned long long> &slicedJacobsthalDiff);

	// * TESTS * //

	void testVectorSort(std::vector<int> &vec, bool print);
	void multipleTestVectorSort(int numTests, int minElements, int maxElements, bool print);

	void testDequeSort(std::deque<int> &deq, bool print);

	void multipleTestDequeSort(int numTests, int minElements, int maxElements, bool print);
	template <typename T>
	void compareVecAndDequeSort(std::vector<T> &vec,
								std::vector<unsigned long long> &slicedJacobsthalDifferences,
								bool print);
	void multipleCompareVecAndDequeSort(int numTests,
										int minElements,
										int maxElements,
										std::vector<unsigned long long> &slicedJacobsthalDifferences,
										bool print);

  private:
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);

	std::vector<int> _vecNumbers;
	std::deque<int> _deqNumbers;

	std::vector<unsigned long long> _jacDiffs;
	std::vector<unsigned long long> _slicedJacDiffs;

	double _durationVec;
	double _durationDeq;
	int _defaultPrecision;

	template <typename RandomAccessIterator, typename Compare>
	// clang-format off
	void binaryInsertionIntoMainChain(const std::vector<unsigned long long> &slicedJacobsthalDiff,
									  std::list<PendChainNode<RandomAccessIterator> > &pendChain,
									  std::list<RandomAccessIterator> &mainChain,
									  Compare compare);
	// clang-format on
	template <typename RandomAccessIterator>
	void finalizeSorting(std::list<RandomAccessIterator> &mainChain, RandomAccessIterator first, std::size_t size);

	template <typename RandomAccessIterator, typename Compare>
	void mergeInsertionSortImpl(RandomAccessIterator first,
								RandomAccessIterator last,
								Compare compare,
								const std::vector<unsigned long long> &slicedJacobsthalDiff);
	template <typename Container>
	bool isSorted(const Container &container);
};

#include "PmergeMe.tpp"

#endif
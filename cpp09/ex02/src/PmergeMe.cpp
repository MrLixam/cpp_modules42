#include <deque>
#include <vector>
#include <iostream>
#include <sys/time.h>
#include "PmergeMe.hpp"

static void mergeDq(std::deque<int>::iterator begin, std::deque<int>::iterator middle, std::deque<int>::iterator end)
{
	std::deque<int> temp;
	std::deque<int>::iterator beg_index = begin, mid_index = middle;

	while (beg_index != middle && mid_index != end)
	{
		if (*beg_index <= *mid_index)
		{
			temp.push_back(*beg_index);
			beg_index++;
		}
		else
		{
			temp.push_back(*mid_index);
			mid_index++;
		}
	}
	temp.insert(temp.end(), beg_index, middle);
	temp.insert(temp.end(), mid_index, end);
	std::copy(temp.begin(), temp.end(), begin);
}

static void mergeSortDq(std::deque<int>::iterator begin, std::deque<int>::iterator end)
{
	if (std::distance(begin, end) > 1)
	{
		std::deque<int>::iterator middle = begin + std::distance(begin, end) / 2;
		mergeSortDq(begin, middle);
		mergeSortDq(middle, end);
		mergeDq(begin, middle, end);
	}
}

static void mergeVec(std::vector<int>::iterator begin, std::vector<int>::iterator middle, std::vector<int>::iterator end)
{
	std::vector<int> temp;
	std::vector<int>::iterator beg_index = begin, mid_index = middle;

	while (beg_index != middle && mid_index != end)
	{
		if (*beg_index <= *mid_index)
		{
			temp.push_back(*beg_index);
			beg_index++;
		}
		else
		{
			temp.push_back(*mid_index);
			mid_index++;
		}
	}
	temp.insert(temp.end(), beg_index, middle);
	temp.insert(temp.end(), mid_index, end);
	std::copy(temp.begin(), temp.end(), begin);
}



static void mergeSortVec(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (std::distance(begin, end) > 1)
	{
		std::vector<int>::iterator middle = begin + std::distance(begin, end) / 2;
		mergeSortVec(begin, middle);
		mergeSortVec(middle, end);
		mergeVec(begin, middle, end);
	}
}

std::ostream& operator<<(std::ostream& outfile, const std::vector<int> vector)
{
	for (std::vector<int>::const_iterator it = vector.begin(); it != vector.end(); it++)
	{
		std::vector<int>::const_iterator it_temp = it;
		it_temp++;
		outfile << *it;
		if (it_temp != vector.end())
			outfile << ' ';
	}
	return (outfile);
}

std::ostream& operator<<(std::ostream& outfile, std::deque<int> deque)
{
	for (std::deque<int>::const_iterator it = deque.begin(); it != deque.end(); it++)
	{
		std::deque<int>::const_iterator it_temp = it;
		it_temp++;
		outfile << *it;
		if (it_temp != deque.end())
			outfile << ' ';
	}
	return (outfile);
}

void sort(std::vector<int>& vecToSort, std::deque<int>& dqToSort)
{
	timeval vecStart, vecEnd, dqStart, dqEnd;

	std::cout << "Unsorted Vector: " << vecToSort << "\n";
	std::cout << "Unsorted Deque: " << dqToSort << "\n"; 

	std::cout << std::endl;

	gettimeofday(&vecStart, NULL);
	mergeSortVec(vecToSort.begin(), vecToSort.end());
	gettimeofday(&vecEnd, NULL);

	gettimeofday(&dqStart, NULL);
	mergeSortDq(dqToSort.begin(), dqToSort.end());
	gettimeofday(&dqEnd, NULL);

	long vecSeconds = vecEnd.tv_sec - vecStart.tv_sec, dqSeconds = dqEnd.tv_sec - dqStart.tv_sec;
	long vecMicros = vecEnd.tv_usec - vecStart.tv_usec, dqMicros = dqEnd.tv_usec - dqStart.tv_usec;

	std::cout << "Sorted Vector: " << vecToSort << "\n";
	std::cout << "Sorted Deque: " << dqToSort << "\n";
	std::cout << "\n";
	std::cout << "Time to sort vector: " << vecSeconds << " Seconds and " << vecMicros << " microseconds\n";
	std::cout << "Time to sort deque: " << dqSeconds << " Seconds and " << dqMicros << " microseconds\n";
}
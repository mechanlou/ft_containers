// #include "truc.hpp"
#include <iostream>
#include <vector>
#include <iterator>

int main(void)
{
	std::vector<int> a(4, 666);

	std::vector<int>::const_reverse_iterator rev_it = a.rbegin();
	std::cout << *rev_it << std::endl;

	// (*rev_it)++;
	while (rev_it != a.rend())
	{
		std::cout << *(rev_it++) << std::endl;
	}

	std::cout << *rev_it << std::endl;
	return (0);
}


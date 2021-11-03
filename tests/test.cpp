// #include "truc.hpp"
#include <iostream>
#include <vector>
#include <iterator>

int main(void)
{
	std::vector<int> a(4, 666);

	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 4;
	std::reverse_iterator<std::vector<int>::iterator> rev_it(a.end());
	std::cout << rev_it[0] << std::endl;

	std::cout << *rev_it << std::endl;
	return (0);
}


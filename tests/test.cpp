// #include "truc.hpp"
#include <iostream>
#include <vector>

int main(void)
{
	const std::vector<int> a(4, 666);

	std::vector<int>::iterator it = a.begin();
	std::cout << *it <<std::endl;
	return (0);
}


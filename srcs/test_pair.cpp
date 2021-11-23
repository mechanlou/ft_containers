#include <iostream>
#include <string>
#include "Pair.hpp"

int main(void)
{
	ft::pair<int, std::string> a(1995, "ok");
	ft::pair<int, std::string> b(a);
	ft::pair<int, std::string> c;
	ft::pair<std::string, float> d;

	d = ft::make_pair("prank", 3.14);
	std::cout << "b first : " << b.first << " b second : " << b.second << std::endl;
	std::cout << "c first : " << c.first << " c second : " << c.second << std::endl;
	std::cout << "d first : " << d.first << " d second : " << d.second << std::endl;
	c = b;
	std::cout << "c first : " << c.first << " c second : " << c.second << std::endl;

	a.first--;
	c.second = "oj";
	std::cout << "a == b ? " << (a == b) << std::endl;
	std::cout << "a == c ? " << (a == c) << std::endl;
	std::cout << "b == c ? " << (a == c) << std::endl;
	std::cout << "a != b ? " << (a != b) << std::endl;
	std::cout << "a != c ? " << (a != c) << std::endl;
	std::cout << "b != c ? " << (b != c) << std::endl;
	std::cout << "a < b ? " << (a < b) << std::endl;
	std::cout << "a < c ? " << (a < c) << std::endl;
	std::cout << "b < c ? " << (b < c) << std::endl;
	std::cout << "a > b ? " << (a > b) << std::endl;
	std::cout << "a > c ? " << (a > c) << std::endl;
	std::cout << "b > c ? " << (b > c) << std::endl;
	std::cout << "a <= b ? " << (a <= b) << std::endl;
	std::cout << "a <= c ? " << (a <= c) << std::endl;
	std::cout << "b <= c ? " << (b <= c) << std::endl;
	std::cout << "a >= b ? " << (a >= b) << std::endl;
	std::cout << "a >= c ? " << (a >= c) << std::endl;
	std::cout << "b >= c ? " << (b >= c) << std::endl;
	return (0);
}
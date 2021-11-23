#include <iostream>
#include "Map.hpp"
#include <vector>
#include <string>
#include "Pair.hpp"


int main(void)
{
	std::cout << "Oy cunt" << std::endl << std::endl;
	std::vector<ft::pair<int, std::string> >	vec(3);

	vec[0].first = 0;
	vec[0].second = "ok";
	vec[1].first = 3;
	vec[1].second = "test";
	vec[2].first = -1;
	vec[2].second = "pran2";

	ft::map<int, std::string>					a;
	ft::map<int, std::string>					b(vec.begin(), vec.end());
	ft::map<int, std::string>					c(b);

	a.print();
	b.print();
	c.print();
	return (0);
}
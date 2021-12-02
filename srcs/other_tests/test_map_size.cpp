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

	std::cout << "a.empty : " << a.empty() << std::endl;
	std::cout << "b.empty : " << b.empty() << std::endl;
	std::cout << "c.empty : " << c.empty() << std::endl << std::endl;

	std::cout << "a.size : " << a.size() << std::endl;
	std::cout << "b.size : " << b.size() << std::endl;
	std::cout << "c.size : " << c.size() << std::endl << std::endl;

	std::cout << "a.max_size : " << a.max_size() << std::endl;
	std::cout << "b.max_size : " << b.max_size() << std::endl;
	std::cout << "c.max_size : " << c.max_size() << std::endl << std::endl;
	return (0);
}
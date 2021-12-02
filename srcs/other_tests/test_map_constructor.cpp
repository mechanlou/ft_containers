#include <iostream>
#include "Map.hpp"
#include <vector>
#include <string>
#include "Pair.hpp"


int main(void)
{
	ft::vector<ft::pair<int, std::string> >	vec(4);

	vec[0].first = 0;
	vec[0].second = "ok";
	vec[1].first = 3;
	vec[1].second = "test";
	vec[2].first = -1;
	vec[2].second = "pran1";
	vec[3].first = -1;
	vec[3].second = "pran2";

	ft::map<int, std::string>					a;
	ft::map<int, std::string>					b(vec.begin(), vec.end());
	ft::map<int, std::string>					c(b);
	return (0);
}
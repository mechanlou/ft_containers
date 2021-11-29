#include "Map.hpp"
#include <string>
#include <vector>

int main(void)
{
	ft::map<int, std::string> a;

	a[25] = "25";
	a[20] = "20";
	a[36] = "36";
	a[10] = "10";
	a[22] = "22";
	a[30] = "30";
	a[40] = "40";
	a[5] = "5";
	a[12] = "12";
	a[28] = "28";
	a[38] = "38";
	a[48] = "48";
	a[1] = "1";
	a[8] = "8";
	a[15] = "15";
	a[45] = "45";
	a[50] = "50";
	
	const ft::map<int, std::string> b(a);

	std::cout << "a.find(38) : " << (*(a.find(38))).second << std::endl;
	std::cout << "b.find(38) : " << (*(b.find(38))).second << std::endl;
	std::cout << "a.size : " << a.size()<< std::endl;
	std::cout << "b.size : " << b.size() << std::endl;
	std::cout << "a.count(1) : " << a.count(1) << std::endl;
	std::cout << "b.count(1) : " << b.count(1) << std::endl;
	std::cout << "a.count(456) : " << a.count(456) << std::endl;
	std::cout << "b.count(456) : " << b.count(456) << std::endl;

	std::cout << "a.lower_boud(39) : " << (*(a.lower_bound(39))).first << std::endl;
	std::cout << "b.lower_boud(39) : " << (*(b.lower_bound(39))).first << std::endl;
	std::cout << "a.lower_boud(-10) is a.end() : " << (a.lower_bound(-10) == a.end()) << std::endl;
	std::cout << "b.lower_boud(-10) is b.end() : " << (b.lower_bound(-10) == b.end()) << std::endl << std::endl;
	std::cout << "a.upper_bound(6) : " << (*(a.upper_bound(6))).first << std::endl;
	std::cout << "b.upper_bound(6) : " << (*(b.upper_bound(6))).first << std::endl;
	std::cout << "a.upper_bound(50) is a.end() : " << (a.upper_bound(50) == a.end()) << std::endl;
	std::cout << "b.upper_bound(50) is b.end() : " << (b.upper_bound(50) == b.end()) << std::endl;

	ft::pair<ft::map<int, std::string>::const_iterator, ft::map<int, std::string>::const_iterator> tmp_pair;
	ft::map<int, std::string>::const_iterator it = b.begin();
	while (it != b.end())
	{
		tmp_pair = b.equal_range((*it).first);
		while (tmp_pair.first != tmp_pair.second)
			std::cout << (*(tmp_pair.first++)).first << std::endl;
		it++;
	}
	return (0);
}
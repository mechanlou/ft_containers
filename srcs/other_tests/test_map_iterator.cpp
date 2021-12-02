#include "Map.hpp"
#include <string>

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

	ft::map<int, std::string>::iterator it = a.begin();
	while (it != a.end())
	{
		std::cout << (*it).first << " : " << (*it).second << std::endl;
		it++;
	}
	it = a.end();
	while (it != a.begin())
	{
		it--;
		std::cout << (*it).first << " : " << (*it).second << std::endl;
	}

	const ft::map<int, std::string> b(a);

	ft::map<int, std::string>::const_iterator const_it = b.begin();
	while (const_it != b.end())
	{
		std::cout << (*const_it).first << " : " << (*const_it).second << std::endl;
		const_it++;
	}
	const_it = b.end();
	while (const_it != b.begin())
	{
		const_it--;
		std::cout << (*const_it).first << " : " << (*const_it).second << std::endl;
	}
	return (0);
}
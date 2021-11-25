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
	
	a.print();

	std::cout << "insert 100 " << (a.insert(ft::make_pair(100, "100"))).second << std::endl;
	std::cout << "insert 100 " << (a.insert(ft::make_pair(100, "100"))).second << std::endl;

	a.print();

	return (0);
}
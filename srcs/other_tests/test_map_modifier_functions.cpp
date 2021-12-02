#include "Map.hpp"
#include <string>
#include <vector>

int main(void)
{
	ft::map<int, std::string> a;
	ft::map<int, std::string> b;
	std::vector<ft::pair<int, std::string> > src;

	src.push_back(ft::make_pair(666, "666"));
	src.push_back(ft::make_pair(1995, "1995"));

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
	

	std::cout << "insert 100 " << (a.insert(ft::make_pair(100, "100"))).second << std::endl;
	std::cout << "insert 100 " << (a.insert(ft::make_pair(100, "100"))).second << std::endl;
	std::cout << "insert -666 hint : " << (*a.insert(a.begin(), ft::make_pair(-666, "-666"))).second << std::endl;


	std::cout << "insert range " << std::endl;
	a.insert(src.begin(), src.end());


	std::cout << "erase iterator " << std::endl;
	a.erase(a.begin());
	std::cout << "erase key " << a.erase(25) << std::endl;
	

	ft::map<int, std::string>::iterator it = a.begin();
	it++; it++;
	a.erase(it, a.end());

	b[89] = "truc";
	b[-7] = "machin";

	std::cout << "container b " << std::endl;

	a.swap(b);
	std::cout << "container b " << std::endl;

	b.clear();

	a.key_comp();
	a.value_comp();
	return (0);
}
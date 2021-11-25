#include <iostream>
#include <map>
#include <string>

int main(void)
{
	std::map<int, std::string> a;

	a[1] = "bite";
	a[2] = "karma";
	a[-1] = "t ki a leur ki l est";
	std::cout << a[1] << " " << a[2] << " " << a[-1] << std::endl;
	std::cout << a.size() << std::endl;
	std::pair<int, std::string> pair1(1, "test");
	std::pair<int, std::string> pair2(pair1);

	std::cout << "max size : " << a.max_size() << std::endl;

	std::map<int, std::string>::iterator it = a.begin();
	while (it != a.end())
	{
		std::cout << (*it).first <<  " "  << (*it).second << std::endl;
		it++;
	}
	std::cout << std::endl;
	a[0] = "truc";
	a[-6] = "chep";
	it = a.begin();
	while (it != a.end())
	{
		std::cout << (*it).first <<  " "  << (*it).second << std::endl;
		it++;
	}
	return (0);
}
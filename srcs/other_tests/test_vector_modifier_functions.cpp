#include "externals.hpp"
#include "Vector.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "Helo fren ༼ つ ◕_◕ ༽つ" << std::endl << std::endl;

	ft::vector<int> a(5, 666);
	ft::vector<int> b(a);
	ft::vector<int> c(2, 2727);
	ft::vector<int>::iterator it1 = a.begin();

	std::cout << "a content :" << std::endl;
	while (it1 != a.end())
	{
		std::cout << *(it1++) << std::endl;
	}
	std::cout << std::endl;

	a.assign(12, 667);
	it1 = a.begin();
	std::cout << "after fill assign :" << std::endl;
	while (it1 != a.end())
	{
		std::cout << *(it1++) << std::endl;
	}
	std::cout << std::endl;

	a.assign(b.begin(), b.end());
	it1 = a.begin();
	std::cout << "after iterator range assign :" << std::endl;
	while (it1 != a.end())
	{
		std::cout << *(it1++) << std::endl;
	}
	std::cout << std::endl;

	a.push_back(1995);
	it1 = a.begin();
	std::cout << "after push_back 1995 :" << std::endl;
	while (it1 != a.end())
	{
		std::cout << *(it1++) << std::endl;
	}
	std::cout << std::endl;

	a.pop_back();
	it1 = a.begin();
	std::cout << "after pop_back :" << std::endl;
	while (it1 != a.end())
	{
		std::cout << *(it1++) << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "resize(capacity)" << std::endl;
	a.resize(a.capacity(), 1427);
	std::cout << "size : " << a.size() << " max_size : " << a.max_size() << std::endl << std::endl;

	a.insert(a.begin(), 1995);
	it1 = a.begin();
	std::cout << "after insert 1995 :" << std::endl;
	while (it1 != a.end())
	{
		std::cout << *(it1++) << std::endl;
	}
	std::cout << std::endl;

	a.insert(a.end() - 3, 0);
	it1 = a.begin();
	std::cout << "after insert 0 :" << std::endl;
	while (it1 != a.end())
	{
		std::cout << *(it1++) << std::endl;
	}
	std::cout << std::endl;

	std::cout << "a = b" << std::endl;
	a = b;
	std::cout << "size : " << a.size() << " max_size : " << a.max_size() << std::endl;
	a.insert(a.begin() + 2, 2, 1995);
	it1 = a.begin();
	std::cout << "after insert fill :" << std::endl;
	while (it1 != a.end())
	{
		std::cout << *(it1++) << std::endl;
	}
	std::cout << std::endl;

	a.insert(a.begin() + 3, c.begin(), c.end());
	it1 = a.begin();
	std::cout << "after insert range :" << std::endl;
	while (it1 != a.end())
	{
		std::cout << *(it1++) << std::endl;
	}
	std::cout << std::endl;

	std::cout << "after erase third element :" << std::endl;
	std::cout << "return value : " << *a.erase(a.begin() + 2) << std::endl;
	it1 = a.begin();
	while (it1 != a.end())
	{
		std::cout << *(it1++) << std::endl;
	}
	std::cout << std::endl;

	std::cout << "after range erase :" << std::endl;
	std::cout << "return value : " << *a.erase(a.begin() + 2, a.begin() + 4) << std::endl;
	it1 = a.begin();
	while (it1 != a.end())
	{
		std::cout << *(it1++) << std::endl;
	}
	std::cout << std::endl;

	a.swap(b);
	std::cout << "a after a.swap(b) :" << std::endl;
	it1 = a.begin();
	while (it1 != a.end())
	{
		std::cout << *(it1++) << std::endl;
	}
	std::cout << "b after a.swap(b) :" << std::endl;
	it1 = b.begin();
	while (it1 != b.end())
	{
		std::cout << *(it1++) << std::endl;
	}
	std::cout << std::endl;

	ft::swap(a, b);
	std::cout << "a after swap(a, b) :" << std::endl;
	it1 = a.begin();
	while (it1 != a.end())
	{
		std::cout << *(it1++) << std::endl;
	}
	std::cout << "b after swap(a, b) :" << std::endl;
	it1 = b.begin();
	while (it1 != b.end())
	{
		std::cout << *(it1++) << std::endl;
	}
	std::cout << std::endl;

	a.clear();
	std::cout << "a after clear :" << std::endl;
	it1 = a.begin();
	while (it1 != a.end())
	{
		std::cout << *(it1++) << std::endl;
	}
	return (0);
}
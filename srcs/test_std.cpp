#include "externals.hpp"
#include <vector>
#include <map>
#include <stack>
#include <iostream>

int	main(void)
{
	std::cout << "Helo ༼ つ ◕_◕ ༽つ" << std::endl;
//vector
	{ // constructors
		std::vector<int>	a;
		std::vector<int>	b(6, 666);
		std::vector<int>	c(b.begin(), b.end());
		std::vector<int> d(c);

		std::vector<int>::iterator it;
		it = c.begin();
		while (it != c.end())
		{
			std::cout << *(it++) << std::endl;
		}

		a = b;
		it = a.begin();
		while (it != a.end())
		{
			std::cout << *(it++) << std::endl;
		}

		std::cout << a[2]++ << std::endl;
		std::cout << a.at(2) << std::endl;
		std::cout << (a[5] = 1995) << std::endl;
		std::cout << --a.at(5) << std::endl;
		try
		{
			std::cout << a.at(6) << std::endl;
		}
		catch(std::exception const & exc)
		{
			std::cerr << "Catched error : " << exc.what() << std::endl;
		}
		std::cout << std::endl;

		it = a.begin();
		while (it != a.end())
			std::cout << (*(it++))++ << std::endl;
		std::cout << std::endl;

		std::vector<int>::const_iterator const_it = a.begin();
		// (*const_it) = 4; //doesnt compile = nice
		while (const_it != a.end())
			std::cout << *(const_it++) << std::endl;
		std::cout << std::endl;

		std::cout << "front : " << a.front() << std::endl;
		std::cout << "back : " << a.back() << std::endl;
	}
	{ // capacity
		int	*vala = new int(4);
		int	*valb = new int(6);


		std::vector<int *>	a(6, vala);
		std::vector<int *>	empty;

		std::cout << "not empty : " << a.empty() << std::endl;
		std::cout << "empty : " << empty.empty() << std::endl << std::endl;

		std::cout << "size before resize : " << a.size() << std::endl;
		std::cout << "capacity before resize : " << a.capacity() << std::endl << std::endl;
		a.resize(20, valb);
		std::cout << "size after first resize : " << a.size() << std::endl;
		std::cout << "capacity after first resize : " << a.capacity() << std::endl;

		std::vector<int *>::iterator it = a.begin();
		while (it != a.end())
			std::cout << **(it++) << std::endl;
		std::cout << std::endl;

		a.resize(8, valb);
		std::cout << "size after second resize : " << a.size() << std::endl;
		std::cout << "capacity after second resize : " << a.capacity() << std::endl;

		it = a.begin();
		while (it != a.end())
			std::cout << **(it++) << std::endl;
		std::cout << std::endl;

		a.reserve(100);
		std::cout << "capacity after reserve 100 : " << a.capacity() << std::endl;
		it = a.begin();
		while (it != a.end())
			std::cout << **(it++) << std::endl;
	}
	{ // iterator
		std::vector<int> a(4, 0);
		std::vector<int>::iterator it1; //default constructor
		std::vector<int>::iterator it2;

		it1 = a.begin(); //copy assignation
		it2 = it1; //copy assignation
		std::vector<int>::iterator it3(it2); //copy constructor

		std::cout << "it1 == it2 ? " << (it1 == it2) << std::endl;
		std::cout << "it1 != it2 ? " << (it1 != it2) << std::endl;
		while (it1 != a.end())
		{
			std::cout << *it1 << std::endl; //operator*
			(*it1)++; 
			it1++; //operator++
		}
		std::cout << "it1 == it2 ? " << (it1 == it2) << std::endl;
		std::cout << "it1 != it2 ? " << (it1 != it2) << std::endl;
		std::cout << std::endl;

		while (it2 != a.end())
		{
			std::cout << *it2 << std::endl;
			(*it2)++;
			++it2; //operator++
		}
		std::cout << std::endl;

		std::cout << "operator+ operator- tests:" << std::endl;
		std::cout << "*(it3 + 1) : " << *(it3 + 1) << std::endl;
		std::cout << "*((it3 + 1) - 1) : " << *((it3 + 1) - 1) << std::endl << std::endl;

		while (it3 != a.end())
		{
			std::cout << *it3 << std::endl;
			(*it3)++;
			it3++;
		}
		std::cout << std::endl;

		std::vector<int>::iterator it4 = a.end();
		while (it4 != a.begin())
		{
			it4--; //operator--
			std::cout << *it4 << std::endl;
			(*it4)++;
		}
		std::cout << std::endl;

		std::cout << "begin > end ? " << (a.begin() > a.end()) << std::endl;
		std::cout << "begin < end ? " << (a.begin() < a.end()) << std::endl;
		std::cout << "begin >= end ? " << (a.begin() >= a.end()) << std::endl;
		std::cout << "begin <= end ? " << (a.begin() <= a.end()) << std::endl;
		std::cout << "begin >= begin ? " << (a.begin() >= a.begin()) << std::endl;
		std::cout << "begin <= begin ? " << (a.begin() <= a.begin()) << std::endl;
		std::cout << "end - begin ? " << (a.end() - a.begin()) << std::endl;

		it4 += 2; //operator -=
		it4 -= 1; //operator +=

		std::cout << "it4[0] after += and -= operations : " << it4[0] << std::endl;
	}
	{ // const_iterator
		std::vector<int> a(4, 1995);
		std::vector<int>::const_iterator it1 = a.begin(); //default constructor
		std::vector<int>::const_iterator it2;

		it1 = a.begin(); //copy assignation
		it2 = it1; //copy assignation
		std::vector<int>::const_iterator it3(it2); //copy constructor

		// (*it1)++; //does not work because its const :D

		std::cout << "it1 == it2 ? " << (it1 == it2) << std::endl;
		std::cout << "it1 != it2 ? " << (it1 != it2) << std::endl;
		while (it1 != a.end())
		{
			std::cout << *it1 << std::endl; //operator*
			it1++; //operator++
		}
		std::cout << "it1 == it2 ? " << (it1 == it2) << std::endl;
		std::cout << "it1 != it2 ? " << (it1 != it2) << std::endl;
		std::cout << std::endl;

		while (it2 != a.end())
		{
			std::cout << *it2 << std::endl;
			++it2; //operator++
		}
		std::cout << std::endl;

		std::cout << "operator+ operator- tests:" << std::endl;
		std::cout << "*(it3 + 1) : " << *(it3 + 1) << std::endl;
		std::cout << "*((it3 + 1) - 1) : " << *((it3 + 1) - 1) << std::endl << std::endl;

		while (it3 != a.end())
		{
			std::cout << *it3 << std::endl;
			it3++;
		}
		std::cout << std::endl;

		std::vector<int>::const_iterator it4 = a.end();
		while (it4 != a.begin())
		{
			it4--; //operator--
			std::cout << *it4 << std::endl;
		}
		std::cout << std::endl;

		std::cout << "begin > end ? " << (a.begin() > a.end()) << std::endl;
		std::cout << "begin < end ? " << (a.begin() < a.end()) << std::endl;
		std::cout << "begin >= end ? " << (a.begin() >= a.end()) << std::endl;
		std::cout << "begin <= end ? " << (a.begin() <= a.end()) << std::endl;
		std::cout << "begin >= begin ? " << (a.begin() >= a.begin()) << std::endl;
		std::cout << "begin <= begin ? " << (a.begin() <= a.begin()) << std::endl;
		std::cout << "end - begin ? " << (a.end() - a.begin()) << std::endl;

		it4 += 2; //operator -=
		it4 -= 1; //operator +=

		std::cout << "it4[0] after += and -= operations : " << it4[0] << std::endl;
	}
	{ // element access
		std::vector<int>	a(6, 666);
		std::vector<int>	empty;

		std::cout << a[2]++ << std::endl;
		std::cout << a.at(2) << std::endl;
		std::cout << (a[5] = 1995) << std::endl;
		std::cout << --a.at(5) << std::endl;
		try
		{
			std::cout << a.at(6) << std::endl;
		}
		catch(std::exception const & exc)
		{
			std::cerr << "Catched error : " << exc.what() << std::endl;
		}
		std::cout << std::endl;

		std::vector<int>::iterator it = a.begin();
		while (it != a.end())
			std::cout << (*(it++))++ << std::endl;
		std::cout << std::endl;

		std::vector<int>::const_iterator const_it = a.begin();
		// (*const_it) = 4; //doesnt compile = nice
		while (const_it != a.end())
			std::cout << *(const_it++) << std::endl;
		std::cout << std::endl;
		
		std::cout << "front : " << a.front() << std::endl;
		std::cout << "back : " << a.back() << std::endl;
	}
	{ // element access
		std::vector<int> a(5, 666);
		std::vector<int> b(a);
		std::vector<int> c(2, 2727);
		std::vector<int>::iterator it1 = a.begin();

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
		
		std::cout << "resize(12)" << std::endl;
		a.resize(12, 1427);
		std::cout << "size : " << a.size() << " capacity : " << a.capacity() << std::endl << std::endl;

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

		std::swap(a, b);
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
	}
	{ // relational operators
		const std::vector<int> a(3, 1995);
		const std::vector<int> b(a);
		std::vector<int> c(a);

		c[2] = 666;
		std::cout << "a == b ? " << (a == b) << std::endl;
		std::cout << "a == c ? " << (a == c) << std::endl;
		std::cout << "a != b ? " << (a != b) << std::endl;
		std::cout << "a != c ? " << (a != c) << std::endl;
		std::cout << "a < b ? " << (a < b) << std::endl;
		std::cout << "a < c ? " << (a < c) << std::endl;
		std::cout << "a > b ? " << (a > b) << std::endl;
		std::cout << "a > c ? " << (a > c) << std::endl;
		std::cout << "a <= b ? " << (a <= b) << std::endl;
		std::cout << "a <= c ? " << (a <= c) << std::endl;
		std::cout << "a >= b ? " << (a >= b) << std::endl;
		std::cout << "a >= c ? " << (a >= c) << std::endl;
	}
// stack
	{
		std::stack<std::string> a;
		std::stack<std::string> b;
		
		std::cout << "a.empty ? " << a.empty() << std::endl;
		a.push("un truc");
		a.push("chep");
		a.push("ok");
		a.push("originalité");
		b.push("un truc");
		b.push("chep");
		b.push("ok");
		b.push("originalité");

		std::cout << "a == b : " << (a == b) << std::endl;
		std::cout << "a != b : " << (a != b) << std::endl;
		std::cout << "a < b : " << (a < b) << std::endl;
		std::cout << "a <= b : " << (a <= b) << std::endl;
		std::cout << "a > b : " << (a > b) << std::endl;
		std::cout << "a >= b : " << (a >= b) << std::endl;

		std::cout << "a.top() : " << a.top() << std::endl;
		std::cout << "a.size() : " << a.size() << std::endl;
		a.pop();
		std::cout << "a.size() after pop : " << a.size() << std::endl;
		std::cout << "a.empty ? " << a.empty() << std::endl;
		std::cout << "a.top() : " << a.top() << std::endl;

		std::cout << "a == b : " << (a == b) << std::endl;
		std::cout << "a != b : " << (a != b) << std::endl;
		std::cout << "a < b : " << (a < b) << std::endl;
		std::cout << "a <= b : " << (a <= b) << std::endl;
		std::cout << "a > b : " << (a > b) << std::endl;
		std::cout << "a >= b : " << (a >= b) << std::endl;
	}
// Map
	{ // accessor
		std::map<int, std::string> a;

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

		std::map<int, std::string>::iterator it = a.begin();
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

		const std::map<int, std::string> b(a);

		std::map<int, std::string>::const_iterator const_it = b.begin();
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
	}
	{ // modifier functions
		std::map<int, std::string> a;
		std::map<int, std::string> b;
		std::vector<std::pair<int, std::string> > src;

		std::cout << "here" << std::endl;
		src.push_back(std::make_pair(666, "666"));
		src.push_back(std::make_pair(1995, "1995"));
		std::cout << "there" << std::endl;

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
		
		std::cout << "stuff" << std::endl;
		std::cout << "insert 100 " << (a.insert(std::make_pair(100, "100"))).second << std::endl;
		std::cout << "insert 100 " << (a.insert(std::make_pair(100, "100"))).second << std::endl;
		std::cout << "insert -666 hint : " << (*a.insert(a.begin(), std::make_pair(-666, "-666"))).second << std::endl;

		std::cout << "insert range " << std::endl;
		a.insert(src.begin(), src.end());
		std::map<int, std::string>::iterator it = a.begin();
		while (it != a.end())
		{
			std::cout << (*it).first << " : " << (*it).second << std::endl;
			it++;
		}

		std::cout << "erase iterator " << std::endl;
		a.erase(a.begin());
		std::cout << "erase key " << a.erase(25) << std::endl;
		it = a.begin();
		while (it != a.end())
		{
			std::cout << (*it).first << " : " << (*it).second << std::endl;
			it++;
		}

		it = a.begin();
		it++; it++;
		a.erase(it, a.end());
		it = a.begin();
		while (it != a.end())
		{
			std::cout << (*it).first << " : " << (*it).second << std::endl;
			it++;
		}

		b[89] = "truc";
		b[-7] = "machin";

		std::cout << "container b " << std::endl;
		it = b.begin();
		while (it != b.end())
		{
			std::cout << (*it).first << " : " << (*it).second << std::endl;
			it++;
		}

		a.swap(b);
		std::cout << "container b " << std::endl;
		it = b.begin();
		while (it != b.end())
		{
			std::cout << (*it).first << " : " << (*it).second << std::endl;
			it++;
		}

		b.clear();

		a.key_comp();
		a.value_comp();
	}
	{ // operation functions
		std::map<int, std::string> a;

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
		
		const std::map<int, std::string> b(a);

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

		std::pair<std::map<int, std::string>::const_iterator, std::map<int, std::string>::const_iterator> tmp_pair;
		std::map<int, std::string>::const_iterator it = b.begin();
		while (it != b.end())
		{
			tmp_pair = b.equal_range((*it).first);
			while (tmp_pair.first != tmp_pair.second)
				std::cout << (*(tmp_pair.first++)).first << std::endl;
			it++;
		}
	}
	{// size
		std::cout << "Oy cunt" << std::endl << std::endl;
		std::vector<std::pair<int, std::string> >	vec(3);

		vec[0].first = 0;
		vec[0].second = "ok";
		vec[1].first = 3;
		vec[1].second = "test";
		vec[2].first = -1;
		vec[2].second = "pran2";

		std::map<int, std::string>					a;
		std::map<int, std::string>					b(vec.begin(), vec.end());
		std::map<int, std::string>					c(b);

		std::cout << "a.empty : " << a.empty() << std::endl;
		std::cout << "b.empty : " << b.empty() << std::endl;
		std::cout << "c.empty : " << c.empty() << std::endl << std::endl;

		std::cout << "a.size : " << a.size() << std::endl;
		std::cout << "b.size : " << b.size() << std::endl;
		std::cout << "c.size : " << c.size() << std::endl << std::endl;

		std::cout << "a.max_size : " << a.max_size() << std::endl;
		std::cout << "b.max_size : " << b.max_size() << std::endl;
		std::cout << "c.max_size : " << c.max_size() << std::endl << std::endl;
	}
	{ // reverse_iterator
		std::map<int, char> a;
		a[0] = 'a';
		a[1] = 'b';
		a[2] = 'c';
		
		std::map<int, char>::reverse_iterator it1 = a.rbegin(); //default constructor
		std::map<int, char>::reverse_iterator it2 = it1; //copy assignation
		std::map<int, char>::reverse_iterator it3(it2); //copy constructor
		
		std::cout << "it1 == it2 ? " << (it1 == it2) << std::endl;
		std::cout << "it1 != it2 ? " << (it1 != it2) << std::endl;
		while (it1 != a.rend())
		{
			std::cout << (*it1).first << " | " << (*it1).second << std::endl; //operator*
			(*it1).second++;
			it1++; //operator++
		}
		std::cout << "it1 == it2 ? " << (it1 == it2) << std::endl;
		std::cout << "it1 != it2 ? " << (it1 != it2) << std::endl;
		std::cout << std::endl;

		while (it3 != a.rend())
		{
			std::cout << (*it3).first << " | " << (*it3).second << std::endl; //operator*
			(*it3).second++;
			it3++;
		}
		std::cout << std::endl;

		std::reverse_iterator<std::map<int, char>::iterator> it4 = a.rend();
		while (it4 != a.rbegin())
		{
			--it4; //operator--
			std::cout << (*it4).first << " | " << (*it4).second << std::endl; //operator*
		}
		std::cout << std::endl;
		}
		return (0);
}

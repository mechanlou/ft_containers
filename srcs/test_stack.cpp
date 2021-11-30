#include "Stack.hpp"
#include <string>

int main(void)
{
	ft::stack<std::string> a;
	ft::stack<std::string> b;
	
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

	std::cout << "a.top() : " << a.top() << std::endl;
	std::cout << "a.size() : " << a.size() << std::endl;
	a.pop();
	std::cout << "a.size() after pop : " << a.size() << std::endl;
	std::cout << "a.empty ? " << a.empty() << std::endl;
	std::cout << "a.top() : " << a.top() << std::endl;
	return (0);
}
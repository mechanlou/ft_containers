#include "externals.hpp"
#include <vector>
#include <iostream>

int	main(void)
{
	std::cout << "Helo fren ༼ つ ◕_◕ ༽つ" << std::endl;
	ft::vector<char>	container(3, 'k');
	ft::reverse_iterator<ft::vector<char>::iterator> reverse_it(container.end());
	
	std::cout << *reverse_it << std::endl;
	return (0);
}
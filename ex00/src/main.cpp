#include <iostream>
#include <deque>
#include <iterator>
#include "../inc/easyfind.hpp"

int main()
{
	std::deque<int> intDeque = {1, 3, 4, 5, 7, 9};
	std::deque<int>::iterator it;
	try
	{
		it = easyfind(intDeque, 6);

		std::cout << "Found value: " << *it << std::endl;
		std::cout << "Index: " << std::distance(intDeque.begin(), it) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		it = easyfind(intDeque, 5);

		std::cout << "Found value: " << *it << std::endl;
		std::cout << "Index: " << std::distance(intDeque.begin(), it) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
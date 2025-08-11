#include "../inc/Span.hpp"
#include <iostream>
#include <cstdlib>
#include <random>

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> dis(1, 100);

	Span sp(5);
	std::cout << sp << std::endl;
	for (size_t i = 0; i < sp.getCapacity(); ++i)
	{
		int n = dis(gen);
		sp.addNumber(n);
		std::cout << n << ", ";
	}
	std::cout << std::endl;
	// std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << sp.longestSpanSlow() << std::endl;
}
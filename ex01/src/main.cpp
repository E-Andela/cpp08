#include "../inc/Span.hpp"
#include <iostream>
#include <cstdlib>
#include <random>

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 100);

	Span sp(100);

	std::vector<int> intVec {1, 3, 5, 6};

	sp.addRange(intVec.begin(), intVec.end());
	sp.addRange(intVec.begin(), intVec.end());
	
	Span sp1(sp);
	
	sp1.addRange(intVec.begin(), intVec.end());
	std::cout << sp << std::endl;
	std::cout << sp1 << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << sp.shortestSpanSlow() << std::endl;
	std::cout << sp.longestSpanSlow() << std::endl;
}
#include "../inc/Span.hpp"
#include <iostream>
#include <bits/stdc++.h>
#include <chrono>

Span::Span()
{

}

Span::Span(unsigned int n) : _maxSize (n)
{
	_numbers.reserve(_maxSize);
}

Span::~Span()
{

}

size_t Span::getSize() const
{
	return _numbers.size();
}

size_t Span::getCapacity() const
{
	return _numbers.capacity();
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw FullException();
	_numbers.push_back(number);
}

static size_t span(int a, int b)
{
	if (a > b)
		return (a - b);
	return (b - a);
}

// size_t Span::shortestSpanSlow()
// {
// 	auto start = std::chrono::high_resolution_clock::now();

// 	if (_numbers.size() < 2)
// 		throw NoSpan();

// 	size_t minSpan {span(_numbers[0], _numbers[1])};
// 	size_t currentSpan {};

// 	for (size_t i = 0; i < _numbers.size(); ++i)
// 	{
// 		for (size_t j = i + 1; j < _numbers.size(); j++)
// 		{
// 			currentSpan = span(_numbers[i], _numbers[j]);
// 			if (currentSpan < minSpan)
// 				minSpan = currentSpan;
// 		}
// 	}

// 	auto end = std::chrono::high_resolution_clock::now();
// 	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
// 	std::cout << "shortestSpan() took: " << duration.count() << " microseconds" << std::endl;

// 	return minSpan;
// }

size_t Span::shortestSpan()
{
	auto start = std::chrono::high_resolution_clock::now();

	std::vector<int> _copy = _numbers;
	std::sort(_copy.begin(), _copy.end());

	size_t minSpan = span(_copy[0], _copy[1]);
	size_t currentSpan {};
	
	for (size_t i = 2; i < _copy.size(); ++i)
	{
		currentSpan = span(_copy[i], _copy[i - 1]);
		if (currentSpan < minSpan)
			minSpan = currentSpan;
		if (minSpan == 0)
			break;
	}

	// for (size_t i = 0; i < _copy.size(); ++i)
	// {
	// 	std::cout << _copy[i] << ", " << _numbers[i] << std::endl;
	// }

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "shortestSpan() took: " << duration.count() << " microseconds" << std::endl;

	return minSpan;
}

size_t Span::longestSpan()
{
	auto start = std::chrono::high_resolution_clock::now();

	if (_numbers.size() < 2)
		throw NoSpan();

	int maxInt = *std::max_element(_numbers.begin(), _numbers.end());
	int minInt = *std::min_element(_numbers.begin(), _numbers.end());

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "Function took: " << duration.count() << " microseconds" << std::endl;

	return (span(maxInt, minInt));
}

size_t Span::longestSpanSlow()
{
	auto start = std::chrono::high_resolution_clock::now();

	if (_numbers.size() < 2)
		throw NoSpan();
	

	size_t maxSpan {span(_numbers[0], _numbers[1])};
	size_t currentSpan {};

	for (size_t i = 0; i < _numbers.size(); ++i)
	{
		for (size_t j = i + 1; j < _numbers.size(); ++j)
		{
			currentSpan = span(_numbers[i], _numbers[j]);
			if (currentSpan > maxSpan)
				maxSpan = currentSpan;
		}
	}

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "Function took: " << duration.count() << " microseconds" << std::endl;

	return maxSpan;
}

const char* Span::FullException::what() const noexcept
{
	return "Vector is full";
}

const char* Span::NoSpan::what() const noexcept
{
	return "No span";
}

std::ostream &operator<<(std::ostream& os, const Span& span)
{
	os << "Size: " << span.getSize() << std::endl;
	os << "Capacity " << span.getCapacity() << std::endl;
	return os;
}
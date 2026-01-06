#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <cstddef>
#include <exception>
#include <iostream>
#include <iterator>

class Span
{
private:
	std::vector<int> _numbers;
	unsigned int _maxSize;
	
public:
	Span();
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();
	Span(Span&& other);
	Span& operator=(Span&& other);
	
	void addNumber(int number);
	
	template <typename Iterator>
	void addRange(Iterator begin, Iterator end)
	{
		size_t count = std::distance(begin, end);
		if (_numbers.size() + count > _maxSize)
			throw FullException();
		for (auto it = begin; it != end; ++it)
		{
			addNumber(*it);
		}
	}

	size_t shortestSpan();
	size_t longestSpan();
	size_t shortestSpanSlow();
	size_t longestSpanSlow();

	size_t getSize() const;
	size_t getCapacity() const;
	int getElement(size_t index) const;
	
	class FullException : public std::exception
	{
	public:
		const char* what() const noexcept override;
	};

	class NoSpan : public std::exception
	{
	public:
		const char* what() const noexcept override;
	};
};

std::ostream &operator<<(std::ostream &os, const Span& span);

#endif
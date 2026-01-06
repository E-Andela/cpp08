#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../inc/Span.hpp"

#define TITLE(x) std::cout << "\n=== " << x << " ===\n"

void test_subject_example()
{
    TITLE("Subject example");

    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
}

void test_empty_span()
{
    TITLE("Empty span");

    Span sp(5);
    try
    {
        sp.shortestSpan();
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try
    {
        sp.longestSpan();
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

void test_single_element()
{
    TITLE("Single element");

    Span sp(5);
    sp.addNumber(42);

    try
    {
        sp.shortestSpan();
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

void test_overflow()
{
    TITLE("Overflow");

    Span sp(3);
    try
    {
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

void test_duplicates()
{
    TITLE("Duplicates");

    Span sp(5);
    sp.addNumber(10);
    sp.addNumber(10);
    sp.addNumber(20);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
}

void test_iterator_range()
{
    TITLE("Iterator range insertion");

    std::vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i * 10);

    Span sp(10);
    sp.addRange(v.begin(), v.end());

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
}

void test_iterator_range_overflow()
{
    TITLE("Iterator range overflow");

    std::vector<int> v(10, 42);
    Span sp(5);

    try
    {
        sp.addRange(v.begin(), v.end());
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

void test_large_span()
{
    TITLE("Large span (10,000 numbers)");

    const int SIZE = 10000;
    Span sp(SIZE);

    std::srand(static_cast<unsigned>(std::time(NULL)));
    for (int i = 0; i < SIZE; i++)
        sp.addNumber(std::rand());

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
}

int main()
{
    test_subject_example();
    test_empty_span();
    test_single_element();
    test_overflow();
    test_duplicates();
    test_iterator_range();
    test_iterator_range_overflow();
    test_large_span();

    return 0;
}
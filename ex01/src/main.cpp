#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <list>
#include <deque>
#include <algorithm>
#include <climits>
#include "../inc/Span.hpp"

void printSeparator(const std::string& title)
{
	std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

void testSubjectExample()
{
	printSeparator("TEST 1: Subject Example");
	
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << "Numbers added: 6, 3, 17, 9, 11" << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
}

void testEmptySpan()
{
	printSeparator("TEST 2: Empty Span Exceptions");
	
	Span sp(5);
	
	std::cout << "Attempting to find shortest span with no elements:" << std::endl;
	try
	{
		sp.shortestSpan();
		std::cout << "ERROR: Should have thrown exception!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	std::cout << "\nAttempting to find longest span with no elements:" << std::endl;
	try
	{
		sp.longestSpan();
		std::cout << "ERROR: Should have thrown exception!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testSingleElement()
{
	printSeparator("TEST 3: Single Element Exception");
	
	Span sp(5);
	sp.addNumber(42);
	
	std::cout << "Added single number: 42" << std::endl;
	std::cout << "Current size: " << sp.getSize() << std::endl;
	
	std::cout << "\nAttempting to find shortest span:" << std::endl;
	try
	{
		sp.shortestSpan();
		std::cout << "ERROR: Should have thrown exception!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	std::cout << "\nAttempting to find longest span:" << std::endl;
	try
	{
		sp.longestSpan();
		std::cout << "ERROR: Should have thrown exception!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testCapacityOverflow()
{
	printSeparator("TEST 4: Capacity Overflow");
	
	Span sp(3);
	
	std::cout << "Span capacity: " << sp.getCapacity() << std::endl;
	std::cout << "Adding 3 numbers..." << std::endl;
	
	try
	{
		sp.addNumber(1);
		std::cout << "Added: 1 (size: " << sp.getSize() << ")" << std::endl;
		sp.addNumber(2);
		std::cout << "Added: 2 (size: " << sp.getSize() << ")" << std::endl;
		sp.addNumber(3);
		std::cout << "Added: 3 (size: " << sp.getSize() << ")" << std::endl;
		
		std::cout << "\nAttempting to add 4th number (should fail):" << std::endl;
		sp.addNumber(4);
		std::cout << "ERROR: Should have thrown exception!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testDuplicateNumbers()
{
	printSeparator("TEST 5: Duplicate Numbers");
	
	Span sp(5);
	sp.addNumber(10);
	sp.addNumber(10);
	sp.addNumber(10);
	sp.addNumber(20);
	sp.addNumber(30);
	
	std::cout << "Numbers added: 10, 10, 10, 20, 30" << std::endl;
	std::cout << "Shortest span (should be 0): " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void testTwoElements()
{
	printSeparator("TEST 6: Two Elements");
	
	Span sp(5);
	sp.addNumber(5);
	sp.addNumber(15);
	
	std::cout << "Numbers added: 5, 15" << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << "(Both should be equal: 10)" << std::endl;
}

void testRangeInsertion()
{
	printSeparator("TEST 7: Range Insertion (Vector)");
	
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i * 10);
	
	std::cout << "Vector contents: ";
	for (int num : v)
		std::cout << num << " ";
	std::cout << std::endl;
	
	Span sp(10);
	sp.addRange(v.begin(), v.end());
	
	std::cout << "Span size after addRange: " << sp.getSize() << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void testRangeWithList()
{
	printSeparator("TEST 8: Range Insertion (List)");
	
	std::list<int> lst;
	lst.push_back(100);
	lst.push_back(50);
	lst.push_back(200);
	lst.push_back(25);
	lst.push_back(150);
	
	std::cout << "List contents: ";
	for (int num : lst)
		std::cout << num << " ";
	std::cout << std::endl;
	
	Span sp(5);
	sp.addRange(lst.begin(), lst.end());
	
	std::cout << "Span size after addRange: " << sp.getSize() << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void testRangeOverflow()
{
	printSeparator("TEST 9: Range Insertion Overflow");
	
	std::vector<int> v(10, 42);
	Span sp(5);
	
	std::cout << "Vector size: " << v.size() << std::endl;
	std::cout << "Span capacity: " << sp.getCapacity() << std::endl;
	std::cout << "\nAttempting to add 10 elements to span with capacity 5:" << std::endl;
	
	try
	{
		sp.addRange(v.begin(), v.end());
		std::cout << "ERROR: Should have thrown exception!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testPartialRangeInsertion()
{
	printSeparator("TEST 10: Partial Range Insertion");
	
	std::vector<int> v;
	for (int i = 0; i < 20; i++)
		v.push_back(i * 5);
	
	std::cout << "Vector size: " << v.size() << std::endl;
	std::cout << "Adding first 10 elements to span..." << std::endl;
	
	Span sp(10);
	sp.addRange(v.begin(), v.begin() + 10);
	
	std::cout << "Span size: " << sp.getSize() << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void testNegativeNumbers()
{
	printSeparator("TEST 11: Negative Numbers");
	
	Span sp(6);
	sp.addNumber(-100);
	sp.addNumber(-50);
	sp.addNumber(0);
	sp.addNumber(50);
	sp.addNumber(100);
	sp.addNumber(150);
	
	std::cout << "Numbers added: -100, -50, 0, 50, 100, 150" << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void testCopyConstructor()
{
	printSeparator("TEST 12: Copy Constructor");
	
	Span sp1(5);
	sp1.addNumber(1);
	sp1.addNumber(2);
	sp1.addNumber(3);
	
	std::cout << "Original span size: " << sp1.getSize() << std::endl;
	std::cout << "Original shortest span: " << sp1.shortestSpan() << std::endl;
	
	Span sp2(sp1);
	std::cout << "\nCopied span size: " << sp2.getSize() << std::endl;
	std::cout << "Copied shortest span: " << sp2.shortestSpan() << std::endl;
	
	sp1.addNumber(10);
	std::cout << "\nAfter adding 10 to original:" << std::endl;
	std::cout << "Original size: " << sp1.getSize() << std::endl;
	std::cout << "Copied size (should be unchanged): " << sp2.getSize() << std::endl;
}

void testAssignmentOperator()
{
	printSeparator("TEST 13: Assignment Operator");
	
	Span sp1(5);
	sp1.addNumber(5);
	sp1.addNumber(10);
	sp1.addNumber(15);
	
	Span sp2(10);
	sp2.addNumber(100);
	
	std::cout << "Before assignment:" << std::endl;
	std::cout << "sp1 size: " << sp1.getSize() << std::endl;
	std::cout << "sp2 size: " << sp2.getSize() << std::endl;
	
	sp2 = sp1;
	
	std::cout << "\nAfter assignment (sp2 = sp1):" << std::endl;
	std::cout << "sp2 size: " << sp2.getSize() << std::endl;
	std::cout << "sp2 shortest span: " << sp2.shortestSpan() << std::endl;
}

void testLargeSpan()
{
	printSeparator("TEST 14: Large Span (10,000 numbers)");
	
	const int SIZE = 10000;
	Span sp(SIZE);
	
	std::srand(static_cast<unsigned>(std::time(NULL)));
	
	std::cout << "Generating " << SIZE << " random numbers..." << std::endl;
	for (int i = 0; i < SIZE; i++)
		sp.addNumber(std::rand());
	
	std::cout << "Span size: " << sp.getSize() << std::endl;
	std::cout << "Calculating spans..." << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void testSequentialNumbers()
{
	printSeparator("TEST 15: Sequential Numbers");
	
	Span sp(100);
	
	std::vector<int> v;
	for (int i = 1; i <= 100; i++)
		v.push_back(i);
	
	sp.addRange(v.begin(), v.end());
	
	std::cout << "Added 1 to 100 sequentially" << std::endl;
	std::cout << "Span size: " << sp.getSize() << std::endl;
	std::cout << "Shortest span (should be 1): " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span (should be 99): " << sp.longestSpan() << std::endl;
}

void testExtremeValues()
{
	printSeparator("TEST 16: Extreme Values");
	
	Span sp(5);
	sp.addNumber(INT_MIN);
	sp.addNumber(-1000000000);
	sp.addNumber(0);
	sp.addNumber(1000000000);
	sp.addNumber(INT_MAX);
	
	std::cout << "Numbers: INT_MIN, -1000000000, 0, 1000000000, INT_MAX" << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

int main()
{
	try
	{
		testSubjectExample();
		testEmptySpan();
		testSingleElement();
		testCapacityOverflow();
		testDuplicateNumbers();
		testTwoElements();
		testRangeInsertion();
		testRangeWithList();
		testRangeOverflow();
		testPartialRangeInsertion();
		testNegativeNumbers();
		testCopyConstructor();
		testAssignmentOperator();
		testLargeSpan();
		testSequentialNumbers();
		testExtremeValues();
		
		printSeparator("ALL TESTS COMPLETED");
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}
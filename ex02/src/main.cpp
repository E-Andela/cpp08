#include <stack>
#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <string>
#include <algorithm>
#include "../inc/MutantStack.hpp"

void printSeparator(const std::string& title)
{
	std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

void testBasicOperations()
{
	printSeparator("TEST 1: Basic Stack Operations");
	
	MutantStack<int> mstack;
	
	std::cout << "Empty stack size: " << mstack.size() << std::endl;
	std::cout << "Is empty: " << (mstack.empty() ? "yes" : "no") << std::endl;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "After pushing 5 and 17:" << std::endl;
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	
	mstack.pop();
	
	std::cout << "After pop:" << std::endl;
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
}

void testIterators()
{
	printSeparator("TEST 2: Iterator Functionality");
	
	MutantStack<int> mstack;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	mstack.push(42);
	
	std::cout << "Forward iteration:" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	
	std::cout << "\nUsing range-based for loop:" << std::endl;
	for (int value : mstack)
	{
		std::cout << value << " ";
	}
	std::cout << std::endl;
}

void testReverseIterators()
{
	printSeparator("TEST 3: Reverse Iterators");
	
	MutantStack<int> mstack;
	
	for (int i = 1; i <= 5; ++i)
		mstack.push(i * 10);
	
	std::cout << "Forward iteration: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "Reverse iteration: ";
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
		std::cout << *rit << " ";
	std::cout << std::endl;
}

void testWithDifferentTypes()
{
	printSeparator("TEST 4: Different Data Types");
	
	// Test with strings
	std::cout << "String MutantStack:" << std::endl;
	MutantStack<std::string> strStack;
	strStack.push("Hello");
	strStack.push("World");
	strStack.push("!");
	
	for (const std::string& str : strStack)
		std::cout << str << " ";
	std::cout << std::endl;
	
	// Test with doubles
	std::cout << "\nDouble MutantStack:" << std::endl;
	MutantStack<double> dblStack;
	dblStack.push(3.14);
	dblStack.push(2.71);
	dblStack.push(1.41);
	
	for (double value : dblStack)
		std::cout << value << " ";
	std::cout << std::endl;
}

void testIteratorManipulation()
{
	printSeparator("TEST 5: Iterator Manipulation");
	
	MutantStack<int> mstack;
	for (int i = 0; i < 10; ++i)
		mstack.push(i);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	std::cout << "First element: " << *it << std::endl;
	
	++it;
	std::cout << "After ++it: " << *it << std::endl;
	
	--it;
	std::cout << "After --it: " << *it << std::endl;
	
	std::cout << "\nEvery second element: ";
	it = mstack.begin();
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
		if (it != ite)
			++it;
	}
	std::cout << std::endl;
}

void testConstIterators()
{
	printSeparator("TEST 6: Const Iterators");
	
	MutantStack<int> mstack;
	mstack.push(100);
	mstack.push(200);
	mstack.push(300);
	
	const MutantStack<int>& constRef = mstack;
	
	std::cout << "Using const iterators: ";
	for (MutantStack<int>::const_iterator cit = constRef.cbegin(); cit != constRef.cend(); ++cit)
		std::cout << *cit << " ";
	std::cout << std::endl;
	
	std::cout << "Using const reverse iterators: ";
	for (MutantStack<int>::const_reverse_iterator crit = constRef.crbegin(); crit != constRef.crend(); ++crit)
		std::cout << *crit << " ";
	std::cout << std::endl;
}

void testSubjectExample()
{
	printSeparator("TEST 7: Subject Example");
	
	std::cout << "MutantStack output:" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	
	std::cout << "\nstd::list output (should match):" << std::endl;
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
}

void testLargeStack()
{
	printSeparator("TEST 8: Large Stack");
	
	MutantStack<int> mstack;
	
	std::cout << "Pushing 1000 elements..." << std::endl;
	for (int i = 0; i < 1000; ++i)
		mstack.push(i);
	
	std::cout << "Stack size: " << mstack.size() << std::endl;
	std::cout << "Top element: " << mstack.top() << std::endl;
	
	std::cout << "First 10 elements: ";
	int count = 0;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end() && count < 10; ++it, ++count)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "Last 10 elements: ";
	count = 0;
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend() && count < 10; ++rit, ++count)
		std::cout << *rit << " ";
	std::cout << std::endl;
}

int main()
{
	try
	{
		testBasicOperations();
		testIterators();
		testReverseIterators();
		testWithDifferentTypes();
		testIteratorManipulation();
		testConstIterators();
		testSubjectExample();
		testLargeStack();
		
		printSeparator("ALL TESTS COMPLETED");
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}
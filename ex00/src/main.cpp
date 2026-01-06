#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <iterator>
#include "../inc/easyfind.hpp"

void printSeparator(const std::string& title)
{
    std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

void testVectorFound()
{
    printSeparator("TEST 1: Vector - Element Found");
    
    std::vector<int> vec = {10, 20, 30, 40, 50};
    
    std::cout << "Vector contents: ";
    for (int val : vec)
        std::cout << val << " ";
    std::cout << std::endl;
    
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Found value: " << *it << std::endl;
        std::cout << "Index: " << std::distance(vec.begin(), it) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void testVectorNotFound()
{
    printSeparator("TEST 2: Vector - Element Not Found");
    
    std::vector<int> vec = {10, 20, 30, 40, 50};
    
    std::cout << "Vector contents: ";
    for (int val : vec)
        std::cout << val << " ";
    std::cout << std::endl;
    
    std::cout << "Searching for: 99" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 99);
        std::cout << "Found value: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void testListFound()
{
    printSeparator("TEST 3: List - Element Found");
    
    std::list<int> lst = {5, 15, 25, 35, 45};
    
    std::cout << "List contents: ";
    for (int val : lst)
        std::cout << val << " ";
    std::cout << std::endl;
    
    try
    {
        std::list<int>::iterator it = easyfind(lst, 25);
        std::cout << "Found value: " << *it << std::endl;
        std::cout << "Distance from begin: " << std::distance(lst.begin(), it) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void testListNotFound()
{
    printSeparator("TEST 4: List - Element Not Found");
    
    std::list<int> lst = {5, 15, 25, 35, 45};
    
    std::cout << "List contents: ";
    for (int val : lst)
        std::cout << val << " ";
    std::cout << std::endl;
    
    std::cout << "Searching for: 100" << std::endl;
    try
    {
        std::list<int>::iterator it = easyfind(lst, 100);
        std::cout << "Found value: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void testDequeFound()
{
    printSeparator("TEST 5: Deque - Element Found");
    
    std::deque<int> deq = {1, 3, 5, 7, 9};
    
    std::cout << "Deque contents: ";
    for (int val : deq)
        std::cout << val << " ";
    std::cout << std::endl;
    
    try
    {
        std::deque<int>::iterator it = easyfind(deq, 5);
        std::cout << "Found value: " << *it << std::endl;
        std::cout << "Index: " << std::distance(deq.begin(), it) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void testDequeNotFound()
{
    printSeparator("TEST 6: Deque - Element Not Found");
    
    std::deque<int> deq = {1, 3, 5, 7, 9};
    
    std::cout << "Deque contents: ";
    for (int val : deq)
        std::cout << val << " ";
    std::cout << std::endl;
    
    std::cout << "Searching for: 6" << std::endl;
    try
    {
        std::deque<int>::iterator it = easyfind(deq, 6);
        std::cout << "Found value: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void testEmptyContainer()
{
    printSeparator("TEST 7: Empty Container");
    
    std::vector<int> vec;
    
    std::cout << "Vector is empty (size: " << vec.size() << ")" << std::endl;
    std::cout << "Searching for: 42" << std::endl;
    
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "Found value: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void testSingleElement()
{
    printSeparator("TEST 8: Single Element");
    
    std::vector<int> vec = {42};
    
    std::cout << "Vector contents: " << vec[0] << std::endl;
    
    std::cout << "\nSearching for existing element (42):" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "Found value: " << *it << std::endl;
        std::cout << "Index: " << std::distance(vec.begin(), it) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\nSearching for non-existing element (99):" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 99);
        std::cout << "Found value: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void testDuplicateElements()
{
    printSeparator("TEST 9: Duplicate Elements (finds first occurrence)");
    
    std::vector<int> vec = {5, 10, 15, 10, 20, 10};
    
    std::cout << "Vector contents: ";
    for (int val : vec)
        std::cout << val << " ";
    std::cout << std::endl;
    
    std::cout << "Searching for: 10 (appears 3 times)" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 10);
        std::cout << "Found value: " << *it << std::endl;
        std::cout << "Index: " << std::distance(vec.begin(), it) << " (should be first occurrence)" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void testNegativeNumbers()
{
    printSeparator("TEST 10: Negative Numbers");
    
    std::list<int> lst = {-50, -25, 0, 25, 50};
    
    std::cout << "List contents: ";
    for (int val : lst)
        std::cout << val << " ";
    std::cout << std::endl;
    
    std::cout << "\nSearching for: -25" << std::endl;
    try
    {
        std::list<int>::iterator it = easyfind(lst, -25);
        std::cout << "Found value: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\nSearching for: 0" << std::endl;
    try
    {
        std::list<int>::iterator it = easyfind(lst, 0);
        std::cout << "Found value: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void testFirstAndLastElements()
{
    printSeparator("TEST 11: First and Last Elements");
    
    std::deque<int> deq = {100, 200, 300, 400, 500};
    
    std::cout << "Deque contents: ";
    for (int val : deq)
        std::cout << val << " ";
    std::cout << std::endl;
    
    std::cout << "\nSearching for first element (100):" << std::endl;
    try
    {
        std::deque<int>::iterator it = easyfind(deq, 100);
        std::cout << "Found value: " << *it << std::endl;
        std::cout << "Index: " << std::distance(deq.begin(), it) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\nSearching for last element (500):" << std::endl;
    try
    {
        std::deque<int>::iterator it = easyfind(deq, 500);
        std::cout << "Found value: " << *it << std::endl;
        std::cout << "Index: " << std::distance(deq.begin(), it) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void testLargeContainer()
{
    printSeparator("TEST 12: Large Container");
    
    std::vector<int> vec;
    for (int i = 0; i < 1000; ++i)
        vec.push_back(i);
    
    std::cout << "Vector size: " << vec.size() << std::endl;
    
    std::cout << "\nSearching for: 777" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 777);
        std::cout << "Found value: " << *it << std::endl;
        std::cout << "Index: " << std::distance(vec.begin(), it) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\nSearching for: 1500 (not in container)" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 1500);
        std::cout << "Found value: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main()
{
    testVectorFound();
    testVectorNotFound();
    testListFound();
    testListNotFound();
    testDequeFound();
    testDequeNotFound();
    testEmptyContainer();
    testSingleElement();
    testDuplicateElements();
    testNegativeNumbers();
    testFirstAndLastElements();
    testLargeContainer();
    
    return 0;
}
/*
 Siddharth Rajan
 CSC 21200
 
 FILE: main.cpp
 This file serves as a way to test the functionality of the sequence template class.
 
 I implemented the sequence template class using a doubly linked list. I don't see any advantage of doing this, because there is no need to perform operations using a two way cursor. Implementing it using a single linked list is a more simplified way of doing it.
 */

#include <iostream>
#include "sequence2.h"
#include "dsequence2.h"
using std::cout;
using std::cin;
using std::endl;
using namespace sid_raj_hw4A;
using namespace sid_raj_hw4B;

int main() {
    
    // This section tests the sequence template class implemented with a single linked list.
    
    cout << "Testing sequence template class with single linked list." << "\n" << endl;
    sequence<int> one;
    cout << "sequence one declared." << endl;
    
    cout << "one: " << one << endl;
    cout << "Size of one: " << one.size() << "\n" << endl;
    
    one.insert(5);
    
    cout << "one (insert function used): " << one << endl;
    cout << "Size of one: " << one.size() << "\n" << endl;
    
    one.insert_first(25);
    
    cout << "one (insert_first function used): " << one << endl;
    cout << "Size of one: " << one.size() << "\n" << endl;
    
    
    one.insert(5);
    one.insert(34);
    one.insert(10);
    one.insert(13);
    one.insert(93);
    
    cout << "one: " << one << endl;
    cout << "Size of one: " << one.size() << "\n" << endl;
    
    one.insert_at(675, 3);
    
    cout << "one (insert_at function used): " << one << endl;
    cout << "Size of one: " << one.size() << "\n" << endl;
    
    sequence<int> two;
    cout << "sequence two declared." << endl;
    
    two.insert(75);
    two.insert(85);
    two.insert(95);
    two.insert(105);
    two.insert(115);
    
    cout << "two: " << two << endl;
    cout << "Size of two: " << two.size() << "\n" << endl;
    
    one += two;
    
    cout << "one (after one += two): " << one << endl;
    cout << "Size of one: " << one.size() << "\n" << endl;
    
    one += 2590;
    
    cout << "one (after one += 2590): " << one << endl;
    cout << "Size of one: " << one.size() << "\n" << endl;
    
    cout << "There are " << one.count(5) << " fives in one." << "\n" << endl;
    
    sequence<int> three;
    cout << "sequence three declared." << endl;
    
    int i = 0;
    while (i < 5) {
        three.insert_first(i);
        ++i;
    }
    
    cout << "three: " << three << endl;
    cout << "Size of three: " << three.size() << "\n" << endl;
    
    sequence<int> sum_one_three = one + three;
    
    cout << "one + three: " << sum_one_three << endl;
    cout << "Size of one + three: " << sum_one_three.size() << "\n" << endl;

    sequence<int> sum_one_500 = one + 500;
    
    cout << "one + 500: " << sum_one_500 << endl;
    cout << "Size of one + 500: " << sum_one_500.size() << "\n" << endl;
    
    cout << "Does two = one? (1 = Yes, 0 = No): " << (two == one) << "\n" << endl;
    
    cout << "Making two = one..." << "\n" << endl;
    
    two = one;
    
    cout << "Now does two = one? (1 = Yes, 0 = No): " << (two == one) << "\n" << endl;
    
    sequence<int> four(three);
    cout << "sequence four declared." << endl;
    
    cout << "After two = one and sequence<int> four(three), these are the sequences:" << "\n" << endl;
    
    cout << "one: " << one << endl;
    cout << "Size of one: " << one.size() << "\n" << endl;

    cout << "two: " << two << endl;
    cout << "Size of two: " << two.size() << "\n" << endl;

    cout << "three: " << three << endl;
    cout << "Size of three: " << three.size() << "\n" << endl;
    
    cout << "four: " << four << endl;
    cout << "Size of four: " << four.size() << "\n" << endl;

    sequence<int> five;
    cout << "sequence five declared." << endl;
    
    cout << "Enter 15 values to insert into five in the line below:" << "\n";
    
    i = 0;
    while (i < 15) {
        cin >> five;
        ++i;
    }
    
    cout << "\nfive: " << five << endl;
    cout << "Size of five: " << five.size() << "\n" << endl;
    
    sequence<int> six;
    cout << "sequence six declared." << endl;
    
    i = 0;
    while (i < 10) {
        six.insert(78);
        six.insert(34);
        six.insert(50);
        ++i;
    }
    
    cout << "six: " << six << endl;
    cout << "Size of six: " << six.size() << "\n" << endl;
    
    six.erase_from(25);
    
    cout << "six (erase_from function called): " << six << endl;
    cout << "Size of six: " << six.size() << "\nSecond to last 34 was removed." << "\n" << endl;
    
    six.erase_first(34);
    
    cout << "six (erase_first function called): " << six << endl;
    cout << "Size of six: " << six.size() << "\nFirst 34 was removed." << "\n" << endl;
    
    six.erase_last(78);
    
    cout << "six (erase_last function called): " << six << endl;
    cout << "Size of six: " << six.size() << "\nLast 78 was removed." << "\n" << endl;
    
    six.erase_occurence(34, 1);
    
    cout << "six (erase_from function called): " << six << endl;
    cout << "Size of six: " << six.size() << "\nSecond 34 was removed." << "\n" << endl;
    
    
    // This section tests the sequence template class implemented with a doubly linked list.
    cout << "Testing sequence template class with doubly linked list." << "\n" << endl;
    dsequence<int> seven;
    
    seven.insert(12);
    seven.insert(100);
    seven.insert_first(54);
    seven.insert_first(100);
    seven.insert(45);
    seven.insert(100);
    seven.insert(134);
    
    cout << "seven (with doubly linked list): " << seven << endl;
    cout << "Size of seven: " << seven.size() << endl;
    cout << "There are " << seven.count(100) << " 100s in seven." << "\n" << endl;
    
    seven.erase_occurence(100, 1);
    
    cout << "seven: " << seven << endl;
    cout << "Size of seven: " << seven.size() << endl;
    cout << "There are " << seven.count(100) << " 100s in seven." << "\n" << endl;
    
    
    cout << "\n" << endl;
    return 0;
}

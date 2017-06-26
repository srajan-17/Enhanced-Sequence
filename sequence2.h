/*
 Siddharth Rajan
 
 CSC 21200
 
 
 
 FILE: sequence2.h
 CLASS PROVIDED: sequence<Item> (a collection of items in a certain order)
 
 TYPEDEFS for the sequence<Item> class:
    sequence<Item>::value_type
    sequence<Item>::value_type is the data type of the items in the sequence. It may be any of the C++ built-in types (int, char, etc.), or a class with a default constructor, a copy constructor, an assignment operator, and a test for equality (x == y).
 
    sequence<Item>::size_type
    sequence<Item>::size_type is the data type of any variable that keeps track of how many items are in a sequence.
 
    sequence<Item>::iterator and sequence<Item>::const_iterator
    Forward iterators for a sequence and const sequence.
 
 CONSTRUCTORS for the sequence<Item> class:
    sequence()
        Postcondition: The sequence is empty.
 
    sequence(const sequence& s2)
        Postcondition: The sequence is initialized as a copy of s2.
 
 ASSIGNMENT OPERATOR for the sequence class:
    sequence& operator =(const sequence& s2)
        Postcondition: The elements in sequence s1 are set to be equal to the elements in sequence s2. Additional memory is allocated if needed.
 
 MODIFICATION MEMBER FUNCTIONS for the sequence<Item> class:
    bool erase_first(const Item& x)
        Postcondition: A boolean is returned indicating whether or not the first occurance of x was erased from the sequence.
 
    bool erase_last(const Item& x)
        Postcondition: A boolean is returned indicating whether or not the last occurance of x was erased from the sequence.
 
    bool erase_occurence(const Item& x, const size_type& n)
        Postcondition: A boolean is returned indicating whether or not the n + 1th occurrence of x was erased from the sequence. (n, the number of the occurrence, starts at 0.)
 
    void erase_from(const size_type& n)
        Postcondition: The element at index n of the sequence is erased. (The index starts at 0.)
 
    void insert(const Item& x)
        Postcondition: x is inserted at the end of the sequence.
 
    void insert_first(const Item& x)
        Postcondition: x is inserted at the start of the sequence.
 
    void insert_at(const Item& x, const size_type& n)
        Postcondition: x is inserted at index n of the sequence. (The index starts at 0.)
 
    void operator +=(const sequence& s2)
        Postcondition: A sequence s1 is increased by the addition of the values of s2 to it.
 
    void operator +=(const Item& x)
        Postcondition: A sequence s1 is increased by the addition of x to it.
 
 CONSTANT MEMBER FUNCTIONS for the sequence<Item> class:
    size_type count(const Item& x) const
        Postcondition: The number of occurrences of x in the sequence is returned.
 
    size_type size() const
        Postcondition: The total number of elements in the sequence is returned.
 
 STANDARD ITERATOR MEMBER FUNCTIONS (provide a forward iterator):
    iterator begin()
    const_iterator begin() const
    iterator end()
    const_iterator end() const
 
 NONMEMBER FUNCTIONS for the sequence<Item> class:
    sequence<Item> operator +(const sequence<Item>& s1, const sequence<Item>& s2)
        Postcondition: The sum of s1 and s2 is returned.
 
    sequence<Item> operator +(const sequence<Item>& s1, const Item& x)
        Postcondition: The sum of s1 and x is returned.
 
    ostream& operator <<(ostream& output, const sequence<Item>& s1)
        Postcondition: The elements of s1 are written to output, and output is the ostream that is returned.
 
    istream& operator >>(istream& input, sequence<Item>& s1)
        Postcondition: The elements of s1 are read from input, and input is the istream that is returned.
 
    bool operator ==(const sequence<Item>& s1, const sequence<Item>& s2)
        Postcondition: The return value is true if s1 and s2 are identical.
 
 VALUE SEMANTICS for the sequence<Item> class:
    Assignments and the copy constructor may be used with sequence objects.
 
 DYNAMIC MEMORY USAGE by the sequence<Item> class:
    If there is insufficient dynamic memory, then the following functions throw bad_alloc: The constructors, the insert functions, the operator += and + functions, and the assignment operator.
 */

#ifndef sequence2_h
#define sequence2_h
#include <cstdlib>
#include "node2.h"

namespace sid_raj_hw4A {
    
    template <class Item>
    class sequence {
    public:
        // TYPEDEFS
        typedef std::size_t size_type;                                                                   // <--done, working
        typedef Item value_type;                                                                         // <--done, working
        typedef node_iterator<Item> iterator;                                                            // <--done, working
        typedef const_node_iterator<Item> const_iterator;                                                // <--done, working
        // CONSTRUCTORS and DESTRUCTOR
        sequence();                                                                                      // <--done, working
        sequence(const sequence& s2);                                                                    // <--done, working
        ~sequence();                                                                                     // <--done, working
        // ASSIGNMENT OPERATOR
        sequence& operator =(const sequence& s2);                                                        // <--done, working
        // MODIFICATION MEMBER FUNCTIONS
        bool erase_first(const Item& x);                                                                 // <--done, working
        bool erase_last(const Item& x);                                                                  // <--done, working
        bool erase_occurence(const Item& x, const size_type& n);                                         // <--done, working
        void erase_from(const size_type& n);                                                             // <--done, working
        void insert(const Item& x);                                                                      // <--done, working
        void insert_first(const Item& x);                                                                // <--done, working
        void insert_at(const Item& x, const size_type& n);                                               // <--done, working
        void operator +=(const sequence& s2);                                                            // <--done, working
        void operator +=(const Item& x);                                                                 // <--done, working
        // CONST MEMBER FUNCTIONS
        size_type count(const Item& x) const;                                                            // <--done, working
        size_type size() const { return many_nodes; }                                                    // <--done, working
        // FUNCTIONS TO PROVIDE ITERATORS
        iterator begin() { return iterator(head_ptr); }                                                  // <--done, working
        const_iterator begin() const { return const_iterator(head_ptr); }                                // <--done, working
        iterator end() { return iterator(); }                                                            // <--done, working
        const_iterator end() const { return const_iterator(); }                                          // <--done, working
    private:
        node<Item> *head_ptr;                                                                            // <--done, working
        size_type many_nodes;                                                                            // <--done, working
    };
    
    // NONMEMBER FUNCTIONS for the sequence<Item> template class
    template <class Item>
    bool operator ==(const sequence<Item>& s1, const sequence<Item>& s2);                                // <--done, working
    
    template <class Item>
    sequence<Item> operator +(const sequence<Item>& s1, const sequence<Item>& s2);                       // <--done, working

    template <class Item>
    sequence<Item> operator +(const sequence<Item>& s1, const Item& x);                                  // <--done, working
    
    template <class Item>
    std::ostream& operator <<(std::ostream& output, const sequence<Item>& s1);                           // <--done, working
    
    template <class Item>
    std::istream& operator >>(std::istream& input, sequence<Item>& s1);                                  // <--done, working
    
}

// FILE: sequence2.template
// IMPLEMENTS: The functions of the sequence template class (see sequence2.h for documentation).
//
// NOTE:
//   Since sequence is a template class, this file is included in sequence2.h.
//   Therefore, we should not put any using directives in this file.
//
// INVARIANT for the sequence class:
//   The link to the first node in the sequence is stored in head_ptr, and the number of nodes in the sequence is stored in many_nodes.

namespace sid_raj_hw4A {

    // IMPLEMENTATIONS for the sequence<Item> class:
    
    // CONSTRUCTORS AND DESTRUCTOR
    template <class Item>
    sequence<Item>::sequence() {
        head_ptr = NULL;
        many_nodes = 0;
    }
    
    template <class Item>
    sequence<Item>::sequence(const sequence<Item>& s2) {
        node<Item> *tail_ptr;
        
        list_copy(s2.head_ptr, head_ptr, tail_ptr);
        many_nodes = s2.many_nodes;
    }
    
    template <class Item>
    sequence<Item>::~sequence() {
        list_clear(head_ptr);
        many_nodes = 0;
    }
    
    // ASSIGNMENT OPERATOR
    template <class Item>
    sequence<Item>& sequence<Item>::operator =(const sequence<Item>& s2) {
        node<Item> *tail_ptr;
        if (this == &s2)
            return *this;
        
        list_clear(head_ptr);
        many_nodes = 0;
        list_copy(s2.head_ptr, head_ptr, tail_ptr);
        many_nodes = s2.many_nodes;
        return *this;
    }
    
    // MODIFICATION MEMBER FUNCTIONS
    template <class Item>
    bool sequence<Item>::erase_first(const Item& x) {
        node<Item> *first_x;
        first_x = list_search(head_ptr, x);                                     // Find where node should be
        if (first_x == NULL)                                                    // Handle case of no x
            return false;
        if (first_x == head_ptr) {                                              // Handle case of node at first element
            list_head_remove(head_ptr);
            --many_nodes;
            return true;
        }
        else if (first_x->link() == NULL) {                                     // Handle case of node at last element
            typename sequence<Item>::size_type position = 1;
            node<Item> *cursor = head_ptr;
            while (position < size()) {
                if (position == size() - 1)
                    break;
                ++position;
                cursor = cursor->link();
            }
            list_remove(cursor);
            --many_nodes;
            return true;
        }
        else {                                                                  // Handle case of node anywhere else
            node<Item> *cursor = head_ptr;
            typename sequence<Item>::size_type position = 0;
            while (cursor != first_x) {
                ++position;
                cursor = cursor->link();
            }
            typename sequence<Item>::size_type i = 0;
            cursor = head_ptr;
            while (i < position) {
                if (i == position - 1)
                    break;
                ++i;
                cursor = cursor->link();
            }
            list_remove(cursor);
            --many_nodes;
            return true;
        }
    }
    
    template <class Item>
    bool sequence<Item>::erase_last(const Item& x) {
        typename sequence<Item>::size_type occur = count(x);
        if (occur == 0)                                                               // Handle case of no x
            return false;
        typename sequence<Item>::size_type position = 0, i = 0;
        node<Item> *last_x = head_ptr;
        for (typename sequence<Item>::iterator p = begin(); p != end(); ++p) {        // Find where node should be
            if (last_x->data() == x) {
                ++i;
                if (i == occur)
                    break;
            }
            ++position;
            last_x = last_x->link();
        }
        if (last_x == head_ptr) {                                                    // Handle case of node at first element
            list_head_remove(head_ptr);
            --many_nodes;
            return true;
        }
        else if (last_x->link() == NULL) {                                           // Handle case of node at last element
            position = 1;
            node<Item> *cursor = head_ptr;
            while (position < size()) {
                if (position == size() - 1)
                    break;
                ++position;
                cursor = cursor->link();
            }
            list_remove(cursor);
            --many_nodes;
            return true;
        }
        else {                                                                       // Handle case of node anywhere else
            node<Item> *cursor = head_ptr;
            i = 0;
            while (i != position - 1) {
                ++i;
                cursor = cursor->link();
            }
            list_remove(cursor);
            --many_nodes;
            return true;
        }
    }
    
    template <class Item>
    bool sequence<Item>::erase_occurence(const Item& x, const typename sequence<Item>::size_type& n) {
        typename sequence<Item>::size_type occur = count(x), i = 0, position = 0;
        if (n >= occur)                                                             // Handle case of no x/invalid index
            return false;
        node<Item> *request_value = head_ptr;
        for (typename sequence<Item>::iterator p = begin(); p != end(); ++p) {      // Find where node should be
            if (request_value->data() == x) {
                ++i;
                if (i == n + 1)
                    break;
            }
            ++position;
            request_value = request_value->link();
        }
        if (request_value == head_ptr) {                                            // Handle case of node at first element
            list_head_remove(head_ptr);
            --many_nodes;
            return true;
        }
        else if (request_value->link() == NULL) {                                   // Handle case of node at last element
            position = 1;
            node<Item> *cursor = head_ptr;
            while (position < size()) {
                if (position == size() - 1)
                    break;
                ++position;
                cursor = cursor->link();
            }
            list_remove(cursor);
            --many_nodes;
            return true;
        }
        else {                                                                      // Handle case of node anywhere else
            node<Item> *cursor = head_ptr;
            i = 0;
            while (i != position - 1) {
                ++i;
                cursor = cursor->link();
            }
            list_remove(cursor);
            --many_nodes;
            return true;
        }
    }
    
    template <class Item>
    void sequence<Item>::erase_from(const typename sequence<Item>::size_type& n) {
        if (n >= many_nodes)                                                       // Handle case of invalid index
            return;
        if (n == 0) {                                                              // Handle case of n = 0
            list_head_remove(head_ptr);
            --many_nodes;
            return;
        }
        size_type i = 0;
        node<Item> *cursor;
        cursor = head_ptr;
        while (i < n) {                                                            // Find where node should be
            if (i == n - 1)
                break;
            ++i;
            cursor = cursor->link();
        }
        list_remove(cursor);
        --many_nodes;
    }
    
    template <class Item>
    void sequence<Item>::insert(const Item& x) {
        if (many_nodes == 0) {
            list_head_insert(head_ptr, x);
            ++many_nodes;
        }
        else {
            node<Item> *cursor;
            cursor = head_ptr;
            while (cursor != NULL) {
                if (cursor->link() == NULL)
                    break;
                cursor = cursor->link();
            }
            list_insert(cursor, x);
            ++many_nodes;
        }
    }
    
    template <class Item>
    void sequence<Item>::insert_first(const Item& x) {
        list_head_insert(head_ptr, x);
        ++many_nodes;
    }
    
    template <class Item>
    void sequence<Item>::insert_at(const Item& x, const typename sequence<Item>::size_type& n) {
        //assert(n <= many_nodes);
        if (n > many_nodes)
            return;
        typename sequence<Item>::size_type i = 0;
        node<Item> *cursor;
        cursor = head_ptr;
        while (i < n) {
            if (i == n - 1)
                break;
            cursor = cursor->link();
            ++i;
        }
        list_insert(cursor, x);
        ++many_nodes;
    }
    
    template <class Item>
    void sequence<Item>::operator +=(const sequence<Item>& s2) {
        node<Item> *copy_head_ptr;
        node<Item> *copy_tail_ptr;
        
        if (s2.many_nodes > 0) {
            list_copy(s2.head_ptr, copy_head_ptr, copy_tail_ptr);
            copy_tail_ptr->set_link(head_ptr);
            head_ptr = copy_head_ptr;
            many_nodes += s2.many_nodes;
        }
    }
    
    template <class Item>
    void sequence<Item>::operator +=(const Item& x) {
        insert_first(x);
    }
    
    // CONSTANT MEMBER FUNCTIONS
    template <class Item>
    typename sequence<Item>::size_type sequence<Item>::count(const Item& x) const {
        size_type answer;
        const node<Item> *cursor;
        answer = 0;
        cursor = list_search(head_ptr, x);
        while (cursor != NULL) {
            ++answer;
            cursor = cursor->link();
            cursor = list_search(cursor, x);
        }
        return answer;
    }
    
    // NONMEMBER FUNCTIONS
    template <class Item>
    sequence<Item> operator +(const sequence<Item>& s1, const sequence<Item>& s2) {
        sequence<Item> answer;
        answer += s1;
        answer += s2;
        return answer;
    }
    
    template <class Item>
    sequence<Item> operator +(const sequence<Item>& s1, const Item& x) {
        sequence<Item> answer;
        answer += s1;
        answer += x;
        return answer;
    }
    
    template <class Item>
    std::ostream& operator <<(std::ostream& output, const sequence<Item>& s1) {
        for (typename sequence<Item>::const_iterator i = s1.begin(); i != s1.end(); ++i) {
            output << *i << " ";
        }
        
        return output;
    }
    
    template <class Item>
    std::istream& operator >>(std::istream& input, sequence<Item>& s1) {
        
        Item x;
        input >> x;
        s1.insert(x);
        
        return input;
    }
    
    template <class Item>
    bool operator ==(const sequence<Item>& s1, const sequence<Item>& s2) {
        if (s1.size() != s2.size())
            return false;
        
        typename sequence<Item>::const_iterator i = s1.begin();
        typename sequence<Item>::const_iterator i2 = s2.begin();
        
        while ((i != s1.end()) && i2 != s2.end()) {
            if (*i != *i2)
                return false;
            ++i;
            ++i2;
        }
        return true;
    }
    
}

#endif /* sequence2_h */

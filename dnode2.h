// Siddharth Rajan

// CSC 21200



// FILE: dnode2.h
// PROVIDES: A template class for a dnode in a linked list, and list manipulation
// functions. The template parameter is the type of the data in each dnode.
// This file also defines a template class: dnode_iterator<Item>.
// The dnode_iterator is a forward iterators with two constructors:
// (1) A constructor (with a dnode<Item>* parameter) that attaches the iterator
// to the specified dnode in a linked list, and (2) a default constructor that
// creates a special iterator that marks the position that is beyond the end of a
// linked list. There is also a const_dnode_iterator for use with
// const dnode<Item>* .
//
// TYPEDEF for the dnode<Item> template class:
//   Each dnode of the list contains a piece of data, a pointer to the
//   next dnode, and a pointer to the previous dnode. The type of the data (dnode<Item>::value_type) is the Item type
//   from the template parameter. The type may be any of the built-in C++ classes
//   (int, char, ...) or a class with a default constructor, an assignment
//   operator, and a test for equality (x == y).
// NOTE:
//   Many compilers require the use of the new keyword typename before using
//   the expression dnode<Item>::value_type. Otherwise
//   the compiler doesn't have enough information to realize that it is the
//   name of a data type.
//
// CONSTRUCTOR for the dnode<Item> class:
//   dnode(const Item& init_data=Item( ),
//         dnode* init_fore=NULL,
//         dnode *init_back=NULL
//   )
//     Postcondition: The dnode contains the specified data, link_fore, and link_back.
//     NOTE: The default value for the init_data is obtained from the default
//     constructor of the Item. In the ANSI/ISO standard, this notation
//     is also allowed for the built-in types, providing a default value of
//     zero. The init_fore and init_back have a default value of NULL.
//
// NOTE about two versions of some functions:
//   The data function returns a reference to the data field of a dnode and
//   the next_link and prev_link function returns a copy of the link field of a dnode.
//   Each of these functions comes in two versions: a const version and a
//   non-const version. If the function is activated by a const dnode, then the
//   compiler choses the const version (and the return value is const).
//   If the function is activated by a non-const dnode, then the compiler choses
//   the non-const version (and the return value will be non-const).
// EXAMPLES:
//    const dnode<int> *c;
//    c->next_link( ) activates the const version of next_link returning const dnode*
//    c->data( ) activates the const version of data returning const Item&
//    c->data( ) = 42; ... is forbidden
//    dnode<int> *p;
//    p->prev_link( ) activates the non-const version of prev_link returning dnode*
//    p->data( ) activates the non-const version of data returning Item&
//    p->data( ) = 42; ... actually changes the data in p's dnode
//
// MEMBER FUNCTIONS for the dnode<Item> class:
//   const Item& data( ) const <----- const version
//   and
//   Item& data( ) <----------------- non-const version
//   See the note (above) about the const version and non-const versions:
//     Postcondition: The return value is a reference to the data from this dnode.
//
//   const dnode* next_link( ) const <----- const version
//   and
//   dnode* next_link( ) <----------------- non-const version
//   See the note (above) about the const version and non-const versions:
//     Postcondition: The return value is the link from this dnode to the next dnode.
//
//   const dnode* prev_link( ) const <----- const version
//   and
//   dnode* prev_link( ) <----------------- non-const version
//   See the note (above) about the const version and non-const versions:
//     Postcondition: The return value is the link from this dnode to the previous dnode.
//
//   void set_data(const Item& new_data)
//     Postcondition: The dnode now contains the specified new data.
//
//   void set_next_link(dnode* new_link)
//     Postcondition: The dnode now contains the specified new link to the next dnode.
//
//   void set_prev_link(dnode* new_link)
//     Postcondition: The dnode now contains the specified new link to the previous dnode.
//
// FUNCTIONS in the linked list toolkit:
//   template <class Item>
//   void list_clear(dnode<Item>*& head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: All dnodes of the list have been returned to the heap,
//     and the head_ptr is now NULL.
//
//   template <class Item>
//   void list_copy
//   (const dnode<Item>* source_ptr, dnode<Item>*& head_ptr, dnode<Item>*& tail_ptr)
//     Precondition: source_ptr is the head pointer of a linked list.
//     Postcondition: head_ptr and tail_ptr are the head and tail pointers for
//     a new list that contains the same items as the list pointed to by
//     source_ptr. The original list is unaltered.
//
//   template <class Item>
//   void list_head_insert(dnode<Item>*& head_ptr, const Item& entry)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: A new dnode containing the given entry has been added at
//     the head of the linked list; head_ptr now points to the head of the new,
//     longer linked list.
//
//   template <class Item>
//   void list_head_remove(dnode<Item>*& head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list, with at
//     least one dnode.
//     Postcondition: The head dnode has been removed and returned to the heap;
//     head_ptr is now the head pointer of the new, shorter linked list.
//
//   template <class Item>
//   void list_insert(dnode<Item>* previous_ptr, const Item& entry)
//     Precondition: previous_ptr points to a dnode in a linked list.
//     Postcondition: A new dnode containing the given entry has been added
//     after the dnode that previous_ptr points to.
//
//   template <class Item>
//   size_t list_length(const dnode<Item>* head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The value returned is the number of dnodes in the linked
//     list.
//
//   template <class dNodePtr, class SizeType>
//   dNodePtr list_locate(dNodePtr head_ptr, SizeType position)
//   The dNodePtr may be either dnode<Item>* or const dnode<Item>*
//     Precondition: head_ptr is the head pointer of a linked list, and
//     position > 0.
//     Postcondition: The return value is a pointer that points to the dnode at
//     the specified position in the list. (The head dnode is position 1, the
//     next dnode is position 2, and so on). If there is no such position, then
//     the null pointer is returned.
//
//   template <class Item>
//   void list_remove(dnode<Item>* previous_ptr)
//     Precondition: previous_ptr points to a dnode in a linked list, and this
//     is not the tail dnode of the list.
//     Postcondition: The dnode after previous_ptr has been removed from the
//     linked list.
//
//   template <class dNodePtr, class Item>
//   dNodePtr list_search
//   (dNodePtr head_ptr, const Item& target)
//   The dNodePtr may be either dnode<Item>* or const dnode<Item>*
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The return value is a pointer that points to the first
//     dnode containing the specified target in its data member. If there is no
//     such dnode, the null pointer is returned.
//
// DYNAMIC MEMORY usage by the toolkit:
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: the constructor, list_head_insert, list_insert, list_copy.


#ifndef dnode2_h
#define dnode2_h
#include <cstdlib>
#include <iterator>

namespace sid_raj_hw4B {
    
    template <class Item>
    class dnode {
    public:
        // TYPEDEF
        typedef Item value_type;
        // CONSTRUCTOR
        dnode(const Item& init_data = Item(), dnode *init_fore = NULL, dnode *init_back = NULL)
        { data_field = init_data; link_fore = init_fore; link_back = init_back; }
        // MODIFICATION MEMBER FUNCTIONS
        Item& data() { return data_field; }
        dnode* next_link() { return link_fore; }
        dnode* prev_link() { return link_back; }
        void set_data(const Item& new_data) { data_field = new_data; }
        void set_next_link(dnode* new_fore) { link_fore = new_fore; }
        void set_prev_link(dnode* new_back) { link_back = new_back; }
        // CONSTANT MEMBER FUNCTIONS
        const Item& data() const { return data_field; }
        const dnode* next_link() const { return link_fore; }
        const dnode* prev_link() const { return link_back; }
    private:
        Item data_field;
        dnode *link_fore;
        dnode *link_back;
    };
    
    // FUNCTIONS to manipulate a doubly linked list:
    template <class Item>
    void list_clear(dnode<Item>*& head_ptr);
    
    template <class Item>
    void list_copy(const dnode<Item>* source_ptr, dnode<Item>*& head_ptr, dnode<Item>*& tail_ptr);
    
    template <class Item>
    void list_head_insert(dnode<Item>*& head_ptr, const Item& entry);
    
    template <class Item>
    void list_head_remove(dnode<Item>*& head_ptr);
    
    template <class Item>
    void list_insert(dnode<Item>* previous_ptr, const Item& entry);
    
    template <class Item>
    std::size_t list_length(const dnode<Item>* head_ptr);
    
    template <class dNodePtr, class SizeType>
    dNodePtr list_locate(dNodePtr head_ptr, SizeType position);
    
    template <class Item>
    void list_remove(dnode<Item>* previous_ptr);
    
    template <class dNodePtr, class Item>
    dNodePtr list_search(dNodePtr head_ptr, const Item& target);
    
    // FORWARD ITERATORS to step through the nodes of a linked list
    // A node_iterator of can change the underlying linked list through the
    // * operator, so it may not be used with a const node. The
    // node_const_iterator cannot change the underlying linked list
    // through the * operator, so it may be used with a const node.
    // WARNING:
    // This classes use std::iterator as its base class;
    // Older compilers that do not support the std::iterator class can
    // delete everything after the word iterator in the second line:
    
    template <class Item>
    class dnode_iterator
    : public std::iterator<std::forward_iterator_tag, Item>
    {
    public:
        dnode_iterator(dnode<Item>* initial = NULL)
        { current = initial; }
        Item& operator *( ) const
        { return current->data( ); }
        dnode_iterator& operator ++( ) // Prefix ++
        {
            current = current->next_link( );
            return *this;
        }
        dnode_iterator operator ++(int) // Postfix ++
        {
            dnode_iterator original(current);
            current = current->next_link( );
            return original;
        }
        bool operator ==(const dnode_iterator other) const
        { return current == other.current; }
        bool operator !=(const dnode_iterator other) const
        { return current != other.current; }
    private:
        dnode<Item>* current;
    };
    
    template <class Item>
    class const_dnode_iterator
    : public std::iterator<std::forward_iterator_tag, const Item>
    {
    public:
        const_dnode_iterator(const dnode<Item>* initial = NULL)
        { current = initial; }
        const Item& operator *( ) const
        { return current->data( ); }
        const_dnode_iterator& operator ++( ) // Prefix ++
        {
            current = current->next_link( );
            return *this;
        }
        const_dnode_iterator operator ++(int) // Postfix ++
        {
            const_dnode_iterator original(current);
            current = current->next_link( );
            return original;
        }
        bool operator ==(const const_dnode_iterator other) const
        { return current == other.current; }
        bool operator !=(const const_dnode_iterator other) const
        { return current != other.current; }
    private:
        const dnode<Item>* current;
    };
    
}

// FILE: dnode2.template
// IMPLEMENTS: The functions of the dnode template class and the
// doubly linked list toolkit (see dnode2.h for documentation).
//
// NOTE:
//   Since dnode is a template class, this file is included in dnode2.h.
//   Therefore, we should not put any using directives in this file.
//
// INVARIANT for the dnode class:
//   The data of a dnode is stored in data_field, the link to the next dnode is stored in link_fore, and the link to the previous dnode is stored in link_back.

#include <cassert>

namespace sid_raj_hw4B {
    
    template <class Item>
    void list_clear(dnode<Item>*& head_ptr) {
        while (head_ptr != NULL)
            list_head_remove(head_ptr);
    }
    
    template <class Item>
    void list_copy(const dnode<Item>* source_ptr, dnode<Item>*& head_ptr, dnode<Item>*& tail_ptr) {
        head_ptr = NULL;
        tail_ptr = NULL;
        
        if (source_ptr == NULL)
            return;
        
        list_head_insert(head_ptr, source_ptr->data());
        tail_ptr = head_ptr;
        
        source_ptr = source_ptr->next_link();
        while (source_ptr != NULL) {
            list_insert(tail_ptr, source_ptr->data());
            tail_ptr = tail_ptr->next_link();
            source_ptr = source_ptr->next_link();
        }
    }
    
    template <class Item>
    void list_head_insert(dnode<Item>*& head_ptr, const Item& entry) {
        if (head_ptr == NULL) {
            head_ptr = new dnode<Item>(entry, head_ptr, NULL);
            return;
        }
        else {
            dnode<Item> *next_ptr;
            next_ptr = head_ptr;
            head_ptr = new dnode<Item>(entry, head_ptr, NULL);
            next_ptr->set_prev_link(head_ptr);
        }
    }
    
    template <class Item>
    void list_head_remove(dnode<Item>*& head_ptr) {
        dnode<Item> *remove_ptr;
        remove_ptr = head_ptr;
        head_ptr = head_ptr->next_link();
        if (head_ptr == NULL) {
            delete remove_ptr;
            return;
        }
        else {
            head_ptr->set_prev_link(NULL);
            delete remove_ptr;
            return;
        }
    }
    
    template <class Item>
    void list_insert(dnode<Item>* previous_ptr, const Item& entry) {
        dnode<Item> *insert_ptr;
        insert_ptr = new dnode<Item>(entry, previous_ptr->next_link(), NULL);
        dnode<Item> *next_ptr = previous_ptr->next_link();
        if (next_ptr == NULL) {
            previous_ptr->set_next_link(insert_ptr);
            insert_ptr->set_prev_link(previous_ptr);
            return;
        }
        else {
            next_ptr->set_prev_link(insert_ptr);
            previous_ptr->set_next_link(insert_ptr);
            insert_ptr->set_prev_link(previous_ptr);
        }
    }
    
    template <class Item>
    std::size_t list_length(const dnode<Item>* head_ptr) {
        const dnode<Item> *cursor;
        std::size_t answer;
        answer = 0;
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->next_link())
            ++answer;
        return answer;
    }
    
    template <class dNodePtr, class SizeType>
    dNodePtr list_locate(dNodePtr head_ptr, SizeType position) {
        dNodePtr cursor;
        SizeType i;
        
        assert(0 < position);
        cursor = head_ptr;
        for (i = 1; (i < position) && (cursor != NULL); ++i)
            cursor = cursor->next_link();
        return cursor;
    }
    
    template <class Item>
    void list_remove(dnode<Item>* previous_ptr) {
        dnode<Item> *remove_ptr;
        dnode<Item> *next_ptr;
        remove_ptr = previous_ptr->next_link();
        next_ptr = remove_ptr->next_link();
        if (next_ptr == NULL) {
            previous_ptr->set_next_link(next_ptr);
            delete remove_ptr;
            return;
        }
        else {
            previous_ptr->set_next_link(next_ptr);
            next_ptr->set_prev_link(previous_ptr);
            delete remove_ptr;
            return;
        }
    }
    
    template <class dNodePtr, class Item>
    dNodePtr list_search(dNodePtr head_ptr, const Item& target) {
        dNodePtr cursor;
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->next_link())
            if (target == cursor->data())
                return cursor;
        return NULL;
    }
    
}

#endif /* dnode2_h */

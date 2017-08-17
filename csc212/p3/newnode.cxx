//	Shofiqur Rahman
//	shofi384@gmail.com

// FILE: newnode.cxx
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field, and the link in link_field.

#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
#include "newnode.h"

using namespace std;

namespace main_savitch_5
{
    size_t list_length(const node* head_ptr) // Library facilities used: cstdlib
	{
	const node *cursor;
	size_t answer;
	answer = 0;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	    ++answer;
	return answer;
    }

    void list_head_insert(node*& head_ptr, const node::value_type& entry)
    {
	head_ptr = new node(entry, head_ptr);
    }

    void list_insert(node* previous_ptr, const node::value_type& entry)
    {
	node *insert_ptr;
	insert_ptr = new node(entry, previous_ptr->link( ));
	previous_ptr->set_link(insert_ptr);
    }

    node* list_search(node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
	node *cursor;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	    if (target == cursor->data( ))
		return cursor;
	return NULL;
    }

    const node* list_search(const node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
	const node *cursor;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	    if (target == cursor->data( ))
		return cursor;
		return NULL;
    }

    node* list_locate(node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
	node *cursor;
	size_t i;
	assert (0 < position);
	cursor = head_ptr;
	for (i = 1; (i < position) && (cursor != NULL); i++)
	    cursor = cursor->link( );
	return cursor;
    }

    const node* list_locate(const node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
	const node *cursor;
	size_t i;
	assert (0 < position);
	cursor = head_ptr;
	for (i = 1; (i < position) && (cursor != NULL); i++)
	    cursor = cursor->link( );
	return cursor;
    }

    void list_head_remove(node*& head_ptr)
    {
	node *remove_ptr;
	remove_ptr = head_ptr;
	head_ptr = head_ptr->link( );
	delete remove_ptr;
    }

    void list_remove(node* previous_ptr)
    {
	node *remove_ptr;
	remove_ptr = previous_ptr->link( );
	previous_ptr->set_link( remove_ptr->link( ) );
	delete remove_ptr;
    }

    void list_clear(node*& head_ptr)
    // Library facilities used: cstdlib
    {
	while (head_ptr != NULL)
	    list_head_remove(head_ptr);
    }

    void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
    // Library facilities used: cstdlib
    {
	head_ptr = NULL;
	tail_ptr = NULL;
	// Handle the case of the empty list.
	if (source_ptr == NULL)
	    return;
	// Make the head node for the newly created list, and put data in it.
	list_head_insert(head_ptr, source_ptr->data( ));
	tail_ptr = head_ptr;
	// Copy the rest of the nodes one at a time, adding at the tail of new list.
	source_ptr = source_ptr->link( );
	while (source_ptr != NULL)
	{
	    list_insert(tail_ptr, source_ptr->data( ));
	    tail_ptr = tail_ptr->link( );
	    source_ptr = source_ptr->link( );
	}
    }

	void list_piece(const node* start_ptr, const node* end_ptr, node*& head_ptr, node*& tail_ptr)
		{
			head_ptr = tail_ptr = NULL;
			if(start_ptr == end_ptr) return;
			list_head_insert(head_ptr, start_ptr->data());
			tail_ptr = head_ptr;
			start_ptr = start_ptr->link();
			while(start_ptr!=end_ptr)
			{
				list_insert(tail_ptr, start_ptr->data());
				start_ptr = start_ptr->link();
				tail_ptr = tail_ptr->link();
			}
		}
//Time Complexity: Since every operation up into the functions is repeated at most once for each node to be copied and none of the operation is dependent on the number of nodes, the time complesity could be denoted in Big O notation as O(n) or linear.

	size_t list_occurrences(const node* head_ptr, const node::value_type& target)
		{
			//assert(head_ptr != NULL);
			size_t s = 0;
			while(head_ptr != NULL)
			{	if(target == head_ptr->data( )) ++s;
				head_ptr = head_ptr->link( );}
			return s;
    }
//Time Complexity: Since every operation up into the functions is repeated at most once for each node to be tested and none of the operation is repeated for the same node, the time complesity could be denoted in Big O notation as O(n) or linear.

	void list_tail_attach(node*& head_ptr, const node::value_type& entry)
		{
			if(head_ptr==NULL)
			{list_head_insert(head_ptr, entry);}
			else
			{node* cursor = head_ptr;
				node* end_ptr = head_ptr->link();
			while(end_ptr!= NULL)
			{cursor = cursor->link( );
				end_ptr = end_ptr->link();}
			list_insert(cursor, entry);}
		}
//Time Complexity: Depending on the number of nodes(n) the list contains pointed to by head_ptr, there will be at most 3n operations. Since every node requires at most one comparison and two assignment operations, and the others are constant functions, not dependent on n. Operation up into the functions is repeated at most once for each node to be tested and none of the operation is repeated for the same node, the time complesity could be denoted in Big O notation as O(n) or linear.

		void list_tail_remove(node*& head_ptr)
		{
			assert(head_ptr != NULL);
			size_t x = list_length(head_ptr);
			if (x == 1)	{list_head_remove(head_ptr);}
			else
				{	node* temp = list_locate(head_ptr, x-1);
					list_remove(temp);}
		}

		/*{
			assert (head_ptr != NULL);
			node* precursor = head_ptr;
			node* end_ptr = head_ptr->link();
			if(end_ptr==NULL)
				{list_head_remove(head_ptr);}
			else
			{end_ptr = end_ptr->link();
				while(end_ptr!= NULL);
				{precursor = precursor->link( );
					end_ptr = end_ptr->link();}
			list_remove(precursor);}
		}*/
//Time Complexity: Depending on the number of nodes(n) the list contains pointed to by head_ptr, there will be at most 3n operations. Since every node requires at most one comparison and two assignment operations, and the others are constant functions, not dependent on n. Operation up into the functions is repeated at most once for each node to be tested and none of the operation is repeated for the same node, the time complesity could be denoted in Big O notation as O(n) or linear.

		node* list_copy_front(const node* source_ptr, size_t n)
		{
			assert(source_ptr != NULL);
			node* head_ptr;
			node* tail_ptr;
			const node* end_ptr = list_locate(source_ptr, n);
			end_ptr = end_ptr->link();
			list_piece(source_ptr, end_ptr, head_ptr, tail_ptr);
			return head_ptr;
		}
//Time Complexity: Depending on the number of nodes(n) the list contains pointed to by head_ptr, there will be at most 8 operations per node totaling to 8n operations. The other operations are constant functions, not dependent on n. Operations up into the functions is repeated at most once for each node to be tested and none of the operation is repeated for the same node, the time complesity could be denoted in Big O notation as O(n) or linear.

}

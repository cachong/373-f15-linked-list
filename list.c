#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);

	list_t* temp_element;

	temp_element = new_element;

	//if new element belongs at end of list
	if (head->next == NULL)
	{
		new_element = new_element->next;
		head->next = temp_element;
	}
	//if new element belongs at beginning of list
	else if (head->index > temp_element->index)
	{
		new_element = new_element->next;
		temp_element->next = head;
		head = temp_element;
	}
	//finding place for new element
	else if (head->next->index > temp_element->index)
	{
		new_element = new_element->next;
		temp_element->next = head->next;
		head->next = temp_element;
	}

	if (new_element != NULL)
	{
		insert_sorted(head->next, new_element);
	}

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);

	list_t* copy_element;

	list_t* next_next_element;

	copy_element = head->next;

	head->next = NULL;

	next_next_element = copy_element->next;

	while(next_next_element != NULL)
	{
		next_next_element = copy_element->next;

		copy_element->next = head;
		head = copy_element;
		copy_element = next_next_element;
	}


	return head;
}


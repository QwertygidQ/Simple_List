#ifndef SIMPLE_LIST_H
#define SIMPLE_LIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct simple_list simple_list;

//-------------------------------------------------------------------------------
/**
 * Creates and returns an instance of simple_list
 * 
 * @param element_size size of any element's size
 * @return created simple_list instance or NULL on fail to create the instance
 */
simple_list* simple_list_create(size_t element_size);

/**
 * Destroys a previously created instance of simple_list
 * 
 * @param list instance of simple_list to destroy
 */
void simple_list_destroy(simple_list* list);

//-------------------------------------------------------------------------------
/**
 * Appends a single element to the simple_list instance
 * 
 * @param list instance of simple_list to append to
 * @param elem element to append to the simple_list instance
 * @return true on success, false on fail
 */
bool simple_list_push_back(simple_list* list, void* elem);

/**
 * Removes a single element from the simple_list instance
 * 
 * @param list instance of simple_list to remove from
 * @param index index of the element to remove from the simple_list instance
 * @return true on success, false on fail
 */
bool simple_list_remove(simple_list* list, size_t index);

//-------------------------------------------------------------------------------
/**
 * Returns the index of the element in the instance of simple_list
 * or -1 if the element is not present in the aforementioned instance
 * 
 * @param list instance of simple_list to search through
 * @param elem element to search for
 * @return index of the element in the instance or -1 on fail to find the element
 */
int simple_list_find(simple_list* list, void* elem);

/**
 * Returns the element at the index in the instance of simple_list
 * @param list instance of simple_list to get the element from
 * @param index index of the element in the instance of simple_list
 * @return element at the index in the instance of simple_list
 */
void* simple_list_at(simple_list* list, size_t index);

//-------------------------------------------------------------------------------
/**
 * Returns the length(number of elements) of the instance of simple_list
 * 
 * @param list instance of simple_list to get the length of
 * @return length of the instance of simple_list
 */
size_t simple_list_length(simple_list* list);

#endif

#include "simple_list.h"

#include <string.h>

struct simple_list
{
    size_t sl_element_size;
    size_t sl_element_count;
    char* sl_data;
};

//-------------------------------------------------------------------------------
bool realloc_data(simple_list* list, size_t new_element_count)
{
    const size_t new_data_size = new_element_count * list -> sl_element_size;
    char* tmp = (char*) realloc(list -> sl_data, new_data_size);
    if (tmp == NULL)
        return false;
    
    list -> sl_element_count = new_element_count;
    list -> sl_data = tmp;
    
    return true;
}

//-------------------------------------------------------------------------------
simple_list* simple_list_create(size_t element_size)
{
    if (element_size < 1)
        return NULL;
    
    simple_list* list = (simple_list*) malloc(sizeof(simple_list));
    if (list != NULL)
    {
        list -> sl_element_size = element_size;
        list -> sl_element_count = 0;
        list -> sl_data = NULL;
    }
    
    return list;
}

void simple_list_destroy(simple_list* list)
{
    free(list -> sl_data);
    free(list);
}

//-------------------------------------------------------------------------------
bool simple_list_push_back(simple_list* list, void* elem)
{
    if (!realloc_data(list, list -> sl_element_count + 1))
        return false;

    return memcpy(simple_list_at(list, list -> sl_element_count - 1), elem, list -> sl_element_size) != NULL;
}

bool simple_list_remove(simple_list* list, size_t index)
{
    if ((list -> sl_element_count > 1) && (index < list -> sl_element_count))
    {
        const size_t length = (list -> sl_element_count - index - 1) * list -> sl_element_size;
        if (memmove(simple_list_at(list, index), simple_list_at(list, index + 1), length) == NULL)
            return false;
        
        return realloc_data(list, list -> sl_element_count - 1);
    }
    else if ((list -> sl_element_count == 1) && (index == 0))
    {
        free(list -> sl_data);
        list -> sl_element_count = 0;
        return true;
    }
    
    return false;
}

//-------------------------------------------------------------------------------
int simple_list_find(simple_list* list, void* elem)
{
    for (size_t i = 0; i < list -> sl_element_count; i++)
        if (memcmp(simple_list_at(list, i), elem, list -> sl_element_size) == 0)
            return i;
        
    return -1;
}

void* simple_list_at(simple_list* list, size_t index)
{
    return list -> sl_data + index * list -> sl_element_size;
}

//-------------------------------------------------------------------------------
size_t simple_list_length(simple_list* list)
{
    return list -> sl_element_count;
}

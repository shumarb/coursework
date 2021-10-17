/*************************************
* Lab 1 Exercise 3
* Name: Sheikh Umar
* Student No: A0149874L
* Lab Group: B08
*************************************/

#include "node.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Copy in your implementation of the functions from ex2.
// There is one extra function called map which you have to fill up too.
// Feel free to add any new functions as you deem fit.
int finds_last_index(list *);
node* finds_last_node(list *);
void prints_list(list *);

// Inserts a new node with data value at index (counting from head
// starting at 0).
// Note: index is guaranteed to be valid.
void insert_node_at(list *lst, int index, int data) {

    // Case 1: lst is empty, so new node is node that head refers to
    // and make new_node refer to itself
    if (lst->head == NULL)
    {   
        // Node creation
        node* new_node;
        new_node = (node*) malloc (sizeof(node));
        new_node->data = data;

        lst->head = new_node;
        new_node->next = new_node;
    } else {
        int is_test = 0;
        int last_index = finds_last_index(lst);
        
        // Case 2: Insert at head
        if (index == 0) {
            if (is_test)
            {
                printf("Insert @ head\n");
            }

            // Node creation
            node* new_node;
            new_node = (node*) malloc (sizeof(node));
            new_node->data = data;

            node* last_node = finds_last_node(lst);
            new_node->next = lst->head;
            lst->head = new_node;
            last_node->next = lst->head;
        } 
        
        // Case 3: Insert at end
        // last-index is 0-based counting
        // and index entered is 1-based counting
        // Eg: List has 4 nodes, so last node is index 3, 
        // user enters index 4 for new node, so new node created
        // will be the new last node.
        else if (index == 1 + last_index)
        {
            // Node creation
            node* new_node;
            new_node = (node*) malloc (sizeof(node));
            new_node->data = data;

            node* last_node = finds_last_node(lst);
            if (is_test) {
                printf("Insert at end\n");
                printf("last node: %d, last node next = %d\n", last_node->data, last_node->next->data);
            }

            last_node->next = new_node;
            new_node->next = lst->head;

            if (is_test)
            {
                printf("After insertion at end:");
                prints_list(lst);
            }
        }
        
        // Case 4: Insert in-between
        else {
            if (is_test) {
                printf("Insert in-between\n");
            }

            // Node creation
            node* new_node;
            new_node = (node*) malloc (sizeof(node));
            new_node->data = data;

            node* curr_node = lst->head;
            int curr_index = 0;
            while(1) {
                if (curr_index == index - 1) {
                    new_node->next = curr_node->next;
                    curr_node->next = new_node;
                    break;
                }
                curr_index += 1;
                curr_node = curr_node->next;
            }
            
            if (is_test)
            {
                printf("After insertion in-between:");
                prints_list(lst);
            }
        }
    }
}


void prints_list(list* lst)
{
    if (lst->head == NULL)
    {
        printf("Empty list\n");
        return;
    }

    node* curr = lst->head;
    node* head = lst->head;
    printf("%d", curr->data);
    printf(" -> ");

    curr = curr->next;
    while (curr != head)
    {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("%d\n", curr->data);
}

// Finds last index in lst
int finds_last_index(list *lst)
{
    int is_test = 0;
    if (lst->head == NULL)
    {
        if (is_test)
        {
            printf("Empty list.\n");
        }
        return 0;
    }

    int last_index = 0;
    node* curr = lst->head;
    node* head = lst->head;
    while(curr->next != head)
    {   
        last_index += 1;
        curr = curr->next;
    }

    if (is_test == 1)
    {
        printf("Last index = %d\n", last_index);
    }

    return last_index;
}


node* finds_last_node(list* lst)
{
    int is_test = 0;
    if (lst->head == NULL)
    {
        if (is_test)
        {
            printf("Empty list.\n");
        }
        return NULL;
    }

    node* head = lst->head;
    node* curr = lst->head;
    while (curr->next != head)
    {
        if (is_test == 1)
        {
            printf("curr: data = %d\n", curr->data);
        }
        curr = curr->next;
    }

    return curr;
}


// Deletes node at index (counting from head starting from 0).
// Note: index is guarenteed to be valid.
void delete_node_at(list *lst, int index) {
    
    int is_test = 0, last_index = finds_last_index(lst);
    if (is_test == 1)
    {
        printf("last_index = %d\n", last_index);
    }
    
    // Case 1: List is empty
    if (lst->head == NULL)
    {
        return;
    } else {
        // Case 2: List has only 1 node and have to delete that node
        if (last_index == 0)
        {   
            // Set next pointer of what head points to to null and free it
            node* to_remove = lst->head;
            to_remove->next = NULL;
            free(to_remove);
            lst->head = NULL;
        } else {
            // Case 3: Delete first node
            if (index == 0) {
                node* last_node = finds_last_node(lst);
                node* to_remove = lst->head;
                node* new_head = to_remove->next;

                last_node->next = new_head;
                lst->head = new_head;
                to_remove->next = NULL;
                free(to_remove);
            } else if (index == last_index) {
                // Case 4: Delete tail
                node* curr_node = lst->head;
                int curr_index = 0;

                while (1) {
                    // Find 2nd last node
                    if (curr_index == index - 1)
                    {  
                        node* to_remove = curr_node->next;
                        curr_node->next = lst->head;
                        to_remove->next = NULL;
                        free(to_remove);
                        break;
                    }
                    curr_node = curr_node->next;
                    curr_index += 1;
                }

            } else {
                // Case 5: Delete in-between
                node* curr_node = lst->head;
                int curr_index = 0;
                while (1) {
                    // Find node before node to be removed
                    if (curr_index == index - 1) {
                        node* to_remove = curr_node->next;
                        curr_node->next = to_remove->next;
                        to_remove->next = NULL;
                        free(to_remove);
                        break;
                    }
                    curr_node = curr_node->next;
                    curr_index += 1;
                }
            }
        }
    }
}

// Rotates list by the given offset.
// Note: offset is guarenteed to be non-negative.
void rotate_list(list *lst, int offset) {

    // Case 1: No rotation for list length < 2 or offset == 0
    int length = 1 + finds_last_index(lst);
    int is_test = 0;
    if (length < 2 || lst->head == NULL || offset == 0) {
        return;
    }
    
    // Case 2: Rotation of at least 1 on list of at least 2 nodes
    // Mark node on index (offset - 1) as kth node based on 0-indexing
    node* curr_node = lst->head;
    int i = 0;
    while (i != offset - 1) {
        curr_node = curr_node->next;
        i += 1;
    }
    node* kth_node = curr_node;
    if (is_test == 1) {
        printf("kth node: %d\n", kth_node->data);
    }

    // Correct starting point after all rotations
    lst->head = kth_node->next;
    if (is_test == 1) {
        printf("new head: %d\n", lst->head->data);
    }
}

// Reverses the list, with the original "tail" node
// becoming the new head node.
// Citation: https://www.youtube.com/watch?v=NC2hGWsyeLo
void reverse_list(list *lst) {

    int is_test = 0;

    // No action if list is empty or number of nodes == 1
    int last_index = finds_last_index(lst);
    if (lst->head == NULL || last_index == 0)
    {   
        if (is_test)
        {
            printf("Empty list or only 1 node. No reverse.\n");
        }
        return;
    }
    
    node* curr_node = lst->head;
    node* next_node = curr_node->next;
    node* prev_node = NULL;

    if (is_test)
    {
        printf("Before reverse, list: ");
        prints_list(lst);
    }

    // Update for first node that head refers to
    curr_node->next = NULL;
    prev_node = curr_node;
    curr_node = next_node;

    while (curr_node != lst->head)
    {
        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    curr_node->next = prev_node;
    lst->head = prev_node;

    if (is_test)
    {
        printf("After reverse, list: ");
        prints_list(lst);
    }
}

// Resets list to an empty state (no nodes) and frees
// any allocated memory in the process
// Citation: https://www.youtube.com/watch?v=ScKTk5GwmG4
void reset_list(list *lst) {
    int is_test = 0;
    if (is_test)
    {
        printf("Reset. Before: ");
        prints_list(lst);
    }
    if (lst->head == NULL)
    {
        if (is_test)
        {
            printf("Reset. Empty list.\n");
        }
        return;
    }

    // Convert to non-circular linked list
    node* last_node = finds_last_node(lst);
    last_node->next = NULL;

    node* curr = lst->head;
    node* next;
    while (curr != NULL)
    {
        next = curr->next;
        free(curr);
        curr = next;
    }

    lst->head = NULL;
    if (is_test)
    {
        printf("After reverse: ");
        node * start = finds_last_node(lst);
        if (start == NULL)
        {
            printf("Empty list\n");
        }
    }
}

// Traverses list and applies func on data values of
// all elements in the list.
void map(list *lst, int (*func)(int)) {
    int is_test = 0;

    if (lst->head == NULL)
    {
        if (is_test)
        {
            printf("Map. Empty list.\n");
        }
        return;
    }

    // Error at line 21 of small_test.in
    // TODO

    if (is_test)
    {
        printf("Map. Before, list: ");
        prints_list(lst);
    }

    node* current_node = lst->head;
    current_node->data = func(current_node->data);
    current_node = current_node->next;

    while (current_node != lst->head)
    {
        current_node->data = func(current_node->data);
        current_node = current_node->next;
    }

    if (is_test)
    {
        printf("Map. After, list: ");
        prints_list(lst);
    }
}


// Traverses list and returns the sum of the data values
// of every node in the list.
long sum_list(list *lst) {

    // Case 1: Empty list
    if (lst->head == NULL)
    {
        return 0;
    }

    long total = 0, is_test = 0;

    if (is_test)
    {
        printf("Map. Before, list: ");
        prints_list(lst);
    }

    node* curr_node = lst->head;
    total += curr_node->data;
    if (is_test)
    {
        printf("Sum. Currently at first node. Total = %ld\n", total);
    }

    curr_node = curr_node->next;
    while (curr_node != lst->head) {
        total += curr_node->data;
        curr_node = curr_node->next;
    }

    if (is_test == 1)
    {
        printf("Sum calculated. Total = %ld\n", total);
    }
    
    return total;
}

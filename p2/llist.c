/* 
 * Implementation of a Linked List 
 * 
 * Prog 2
 * Dalton Tarde
 * CS-320 Section 1
 * October 6, 2020 
 */ 
#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

/** 
 * Dynamic list from a string (char[] in C)
 * Then, prints current string with each call to strToList
 * Finally, returns head of new list
 * 
 * @param s[] (character String) 
 */
Link strToList(char s[]) {
    Link head = malloc(sizeof(Node)); 

    if (s[0] != '\0') { 
        printf("%.*s: %c\n", (int)sizeof(s)+1, s, s[0]);
        head->data = s[0]; 
        char * ps = s+1;
        head->next = strToList(ps); 
    }
        return head; 
}

/** 
 * Recurse through elements in the list
 * then return int for size 
 * 
 * @param head 
 */
int size(Link head){
    if (head == NULL) { 
        return 0; 
    }
    return 1 + size(head->next); 
}

/** 
 * Recursively iterates through the list to locate the Data element
 *     - NULL if list is empty or it reaches end of list
 *     - Returns Link a pointer to the Data element if found
 * 
 * @param c, head 
 */
Link find(Data c, Link head){
    if (head == NULL) { 
        return NULL; 
    }
    if (head->data == c) { 
        return head; 
    }
    return find(c, head->next); 
}

/** 
 * Adds element q to the list inbetween p1 and p2 (parameters)
 * Returns void, requires args passed to insert to be valid Link elements
 * 
 * @param p1, p2, q 
 */
void insert(Link p1, Link p2, Link q){
    p1->next = q->next; 
    q->next = p2;  
}

/** 
 * Removes element q whose predecessor is element p
 * Returns void (q contains a pointer to the removed element)
 * 
 * @param p, q
 */
void delete(Link p, Link q){
    p->next = q->next; 
    q = NULL; 
    free(q); 
    return;
}

/**
 * Deletes one (1) element from the list, using recursion 
 * and freeing up memory as each element is removed
 * Prints the element being deleted until whole list is deleted
 * Returns void 
 * 
 * @param head 
 */
void deleteList(Link head){

    if (head == NULL) { 
     return; 
    }
    
    printf("deleting ");
    printf(head); 
    printf("\n"); 

    if (head->next) { 
        deleteList(head->next); 
    }
    free(head);
    head = NULL; 
}

/** 
 * Recursively prints list elements
 * Returns void
 * 
 * @param head 
 */
void print(Link head){
    if (head != NULL) { /* recursive call */
        printf("%c ", head->data);
        print(head->next); 
    }
    else { /* end condition */  
        return; 
    }
}

/* 
 * Prog 2 uses various C utilities (makefile, fileopen.c)
 * and a driver (p2.c) to navigate an implementation of a 
 * linked list using prototype declarations in llist.h 
 * 
 * The program will determine if a single-line file can be read
 * through prior to moving through the linked list implementation 
 * 
 * Prog 2
 * Dalton Tarde
 * CS-320 Section 1
 * October 6, 2020 
 */ 
#include<stdio.h>
#include<stdlib.h> 
#include "llist.h"

/* Class Prototypes: */ 
void printId(); 
int main(int argc, char *argv[], const char **file); 

/**
 * Identification printout for Edoras 
 *
 * @return void 
 */
void printId() { 
    printf("Program 2, cssc2670, Dalton Tarde\n\n");  
}

/**
 * Verifies File I/O, acts as driver for llist.c 
 *
 * @param argc, *argv[] 
 * @return void 
 */
int main(int argc, char *argv[], const char **filein) {
    FILE * db;
    char buffer[100]; 

    printId(); 

    if (argc != 2) { /* Checks for file passed via command line */ 
        perror("Input file error"); 
        return -1; 
    } 

    FILE *file; 
    if (file != fopen(filein, "r")) {  /* Checks name of file */ 
        fclose(file); 
        perror("Error opening file"); 
        return -1; 
    }
    
    db = fopen(argv[1], "r"); 

    /* File content put into String buffer and buffer is echoed */ 
    while (EOF != fscanf(db, "%[^\n]\n", buffer)){
        printf("> %s\n", buffer); 
    }

    Link head = strToList(buffer); 

    print(head);  
    printf("\n"); 
    printf("%d\n", size(head) - 1);  

    Link toAssign = find('t', head);  
    Link elementBefore = toAssign;  
    Link elementAfter = elementBefore->next; 
    Link addition = 'o';  

    /*insert(elementBefore, elementAfter, addition);*/  

    printf("\n"); 
    printf("%d\n", size(head) -1);  
    print(head); 
    printf("\n");

    Link element2 = head->next; 
    Link element3 = element2->next; 

    delete(element2, element3);
    print(head); 
    printf("\n");   
   
    deleteList(head); 

    fclose(db); 
    return 0; 
    
}

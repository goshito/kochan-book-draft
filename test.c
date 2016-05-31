/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* Chapter 11, Exercise 3
 * File:   insEntryFron.c
 * Author: georgi
 *
 * Created on May 30, 2016, 5:09 PM
 * 3. The function developed in exercise 2 only inserts an element after an existing ele-
ment in the list, thereby preventing you from inserting a new entry at the front of
the list. How can you use this same function and yet overcome this problem?
(Hint: Think about setting up a special structure to point to the beginning of the
list.)
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * must fix displayed results
 * how to change list pointer to point to the new
 * 
 */
struct entry {
    int value;
    struct entry *next;
};

int main(int argc, char** argv) {
    void insertEntry(struct entry *insert, struct entry *where);
    void printList(struct entry *list_pointer);
    
    //my structures and a pointer to the beginning of the list
    struct entry n1, n2, n3, *list_start = &n1;
    //this will be inserted at the beginning of the list   
    struct entry n0, *ptr_n0 = &n0, *ptr_n1 = &n1;
    
    
    n0.value = 50;
    n0.next = &n1;
    
    n1.value = 100;
    n1.next = &n2;
    
    n2.value = 200;
    n2.next = &n3;
    
    n3.value = 300;
    n3.next = (struct entry *) 0;
    
    //display the linked list before insert
    printf("Linked list before insert:"); 
    printList(list_start);
    //insert n21 after n2
    insertEntry(new_first, old_first);
    //display the linked list
    printf("\nLinked list after insert:");
    printList(list_start);

    return (EXIT_SUCCESS);
}

//function to insert an entry into the linked list's beginning
void insertEntry(struct entry *insert, struct entry *after) {
    
    insert->value = 50;
    insert->next = after->next;
    after->next = insert;
    
}
//function to display the contents of the linked list
void printList(struct entry *list_pointer) {
    
    while (list_pointer != (struct entry *) 0) {
        printf("%i", list_pointer->value);
        list_pointer = list_pointer->next;
        if (list_pointer)
            printf(",");
    }
    
}
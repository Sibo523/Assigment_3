#include <stdio.h>
#include <stdlib.h> // For malloc
#include <string.h>
#include "StrList.h"

// typedef struct _Node {
//     char* value;
//     struct _Node* next;
// } Node;

// typedef struct _StrList {
//     struct _Node* head;
//     int size; 
// } StrList;

StrList* StrList_alloc() {
    StrList* newList = (StrList*)malloc(sizeof(StrList));  // Allocate memory for the entire structure
    if (newList == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for StrList.\n");
        return NULL;
    }
    // struct newList.head

    // Initialize members
    newList->head = NULL;  // Use -> to access members through pointer
    newList->size = 0;

    return newList;

}
void StrList_free(StrList* list) {
    Node *current = list->head;
    Node* next;

    while (current != NULL) {
        next=current->next;
        free(current->value);
        free(current);
        current = next;
    }
    free(list);
}

size_t StrList_size(const StrList* StrList){
    return StrList->size; // W 
}


void StrList_insertLast(StrList* StrList, const char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Corrected allocation size
    if (newNode == NULL) {
        fprintf(stderr, "Unable to allocate memory for new node\n");
        exit(-1); // Or handle the error as appropriate for your program
    }

    // Create a copy of the string
    newNode->value = strdup(data);
    if (newNode->value == NULL) {
        fprintf(stderr, "Unable to allocate memory for new node's value\n");
        free(newNode); // Free the node memory
        exit(-1); // Or handle the error as appropriate for your program
    }

    newNode->next = NULL;

    // Check for an empty list
    if (StrList->head == NULL) {
        StrList->head = newNode;
    } else {
        Node* current = StrList->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void StrList_insertAt(StrList* StrList, const char* data, int index) {
    // if (index < 0 || index >= StrList->size) {
    //     // Handle invalid index (e.g., print error message or return)
    //     return;
    // }

    Node* current = StrList->head;
    for (int i = 0; i < index-1; ++i) {
        current = current->next;
    }

    Node* temp = (index == 0) ? NULL : current->next;
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        // Handle memory allocation failure
        return;
    }

    newNode->value = strdup(data);
    if (newNode->value == NULL) {
        // Handle string allocation failure
        free(newNode);
        return;
    }

    newNode->next = temp;
    current->next = newNode;
    StrList->size++;
}
char* StrList_firstData(const StrList* StrList){
    return StrList->head->value;
}

void StrList_print(const StrList* StrList){
    Node *current = StrList->head;
    while(current != NULL){
        printf("%s\n",current->value);
        current = current->next;
    }
}

void StrList_printAt(const StrList* Strlist,int index){
    Node *current = Strlist->head;
    for(int i = 0; i < index;i++){
        current = current->next;
    }
    printf("%s",current->value);
}

int StrList_printLen(const StrList* Strlist){
    int counter = 0;
    Node *current = Strlist->head;
    while (current != NULL){
        counter += strlen(current->value);
        current = current->next;
    }
    return counter;
}

int StrList_count(StrList* StrList, const char* data){
    Node *current = StrList->head;
    int counter = 0;
    while(current != NULL){
        if (strcmp(current->value,data)==0){
            counter += 1;
        }
        current = current->next;
    }
    return counter;
}


void StrList_remove(StrList* StrList, const char* data){ // need to do 
    Node *current = StrList->head;
    Node* perv = current;
    if (strcmp(current->value, data)==0){
        StrList->head = current->next;
        StrList->size -= 1;
    }
    // printf("%s",StrList->head->value);
    
    while (current != NULL){
        if(strcmp(data,current->value) == 0){
            Node *temp = current->next;
            perv->next = temp;
            free(current);
            current = temp; 
            StrList->size -= 1;
        }
        perv = current;
        if (current != NULL){
        current = current->next;
        }
    }
}
void StrList_removeAt(StrList* StrList, int index){
    Node* current = StrList->head;
    
    if (index == 0){
        StrList->head = StrList->head->next;
        // free(current->value);
        free(current);
        StrList->size -= 1;
    }
    else{
        for (int i = 0; i < index-1; i++)
        {
            current = current->next;
        }
        Node* temp = current->next->next;
        // prev = current;
        // current = current
        free(current->next->value);
        free(current->next);
        current->next = temp;
    }
}

char* str_clone(const char* str) {
    return str ? strdup(str) : NULL;
}

StrList* StrList_clone(const StrList* original) {
    if (original == NULL) {
        return NULL;
    }

    StrList* clone = StrList_alloc();
    Node* current = original->head;
    Node** next_ptr = &clone->head;
    clone->size = original->size;

    while (current != NULL) {
        *next_ptr = (Node*)malloc(sizeof(Node));  // Allocate memory for a new node
        (*next_ptr)->value = str_clone(current->value);  // Copy string value
        (*next_ptr)->next = NULL;  // Set next pointer of new node to NULL (temporarily)

        // Correct assignment: Move `next_ptr` to the `next` pointer of the newly allocated node
        next_ptr = &(*next_ptr)->next;

        current = current->next;  // Move to the next node in the original list
    }

    return clone;
}

void StrList_reverse( StrList* StrList){
    Node* current = StrList->head->next;
    Node* perv = StrList -> head;
    perv->next = NULL;// base 
    Node *temp = current->next; // temp = cur +1 
    
    
    while (temp != NULL){
        current->next = perv;
        perv = current;
        current = temp;
        temp = temp->next;
    }
    current->next = perv; 
    StrList->head = current;
}
int compare_strings(const void* a, const void* b) {
    char* str1 = *(char**)a; // Cast to char*
    char* str2 = *(char**)b; // Cast to char*
    return strcmp(str1,str2);
}

void StrList_sort(StrList* list) {
    if (list == NULL || list->size ==  0) {
        return; // Empty list or invalid list, nothing to sort
    }

    // Allocate an array to hold the string values
    char** values = malloc(list->size * sizeof(char*));
    if (values == NULL) {
        // Handle memory allocation failure
        return;
    }

    // Populate the array with string pointers from the list nodes
    Node* current = list->head;
    int i =  0;
    while (current != NULL) {
        values[i++] = current->value;
        current = current->next;
    }

    // Use qsort to sort the array of string pointers
    qsort(values, list->size, sizeof(char*), compare_strings);

    // Update the list nodes with the sorted values
    current = list->head;
    i =  0;
    while (current != NULL) {
        printf("Sorted string: %s\n", values[i]);
        // Copy the sorted string into the node's value field
        current->value = strdup(values[i]);
        current = current->next;
        i++;
    }
    
    free(values); // Free the temporary array
}




int StrList_isSorted(StrList* StrList){
    Node *current = StrList->head;
    while (current->next != NULL){
        if(!strcmp(current->value,current->next->value)){
            return 0;
        }
        current = current->next;
    }
    return 1;
}


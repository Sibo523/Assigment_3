#include <stdio.h>
#include <stdlib.h> // For malloc
#include <string.h>
#include "StrList.h"

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
    Node* current = list->head;
    Node* next;

    while (current != NULL) {
        next = current->next; // Save the next node before freeing the current
        free(current->value); // Free the data if it was dynamically allocated
        free(current); // Then free the node itself
        current = next; // Move to the next node
    }

    list->head = NULL; // Set the head to NULL after freeing all nodes
    list->size =  0; // Reset the size to  0
}

size_t StrList_size(const StrList* StrList){
    Node* cur = StrList->head;
    int count = 0;
    while(cur != NULL){
        count++;
        cur = cur->next;
    }
    return count; // W 
}


void StrList_insertLast(StrList* StrList, const char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Corrected allocation size
    newNode->value = (char*)malloc(sizeof(char)*strlen(data) + sizeof(char));
    if (newNode == NULL) {
        fprintf(stderr, "Unable to allocate memory for new node\n");
        exit(-1); // Or handle the error as appropriate for your program
    }
    if (StrList->head == NULL){
        strcpy(newNode->value ,data);
        StrList->head =  newNode;
        return;
    }
    // Create a copy of the string
    strcpy(newNode->value,data);
    // newNode->value = strdup(data);
    if (newNode->value == NULL) {
        fprintf(stderr, "Unable to allocate memory for new node's value\n");
        // free(newNode); // Free the node memory
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
    if (StrList == NULL||StrList->head == NULL){
        return;
    }
    Node *current = StrList->head;
    while(current->next != NULL){
        printf("%s ",current->value);
        current = current->next;
    }
    printf("%s\n",current->value);
}

void StrList_printAt(const StrList* Strlist,int index){
    Node *current = Strlist->head;
    for(int i = 0; i < index;i++){
        current = current->next;
    }
    printf("%s\n",current->value);
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
    if (StrList == NULL || StrList->head == NULL){
        return;
    }
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
            if (current == NULL){
                return;
            }
        }
        if(current->next == NULL){
            return;
        }
        Node* temp = current->next->next;
        // prev = current;
        // current = current
        free(current->next->value);
        free(current->next);
        current->next = temp;
    }
}

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
    if (((StrList1 == NULL) && (StrList2 == NULL)) || ((StrList1->head == NULL) &&(StrList2->head == NULL))){
        return 1;
    }
    if (((StrList1 == NULL) ^ (StrList2 == NULL)) || ((StrList1->head == NULL) ^ (StrList2 == NULL))){
        return 0;
    }
    Node* cur_1 = StrList1->head;
    Node* cur_2 = StrList2->head;

    while (cur_1 != NULL || cur_2 != NULL){

        if (strcmp(cur_1->value,cur_2->value) != 0){
            return 0;
        }
        cur_1 = cur_1->next;
        cur_2 = cur_2->next;
    }
    if ((cur_1 != NULL )^ (cur_2 != NULL)){
        return 0;
    }
    return 1;
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
    if (StrList == NULL || StrList->head == NULL){
        return;
    }
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
    if (list == NULL || list->head == NULL) {
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
    int size = StrList_size(list);

    // Use qsort to sort the array of string pointers
    qsort(values, size, sizeof(char*), compare_strings);
    
    // Update the list nodes with the sorted values
    current = list->head;
    i =  0;
    while (current != NULL) {
        current->value = values[i];
        current = current->next;
        i++;
    }
    free(values); // Free the temporary array
}




int StrList_isSorted(StrList* StrList){
    Node *current = StrList->head;
    while (current->next != NULL){
        if(strcmp(current->value,current->next->value)>0){
            return 0;
        }
        current = current->next;
    }
    return 1;
}
// StrList* buildList( char* str,int length){
//     StrList* List;
//     int count = 0;
//     int j = 0;
//     char* substring;

//     for (int i = 0; i < length; i++)
//     {
//         while (str[j] != ' ' && j < strlen(str))
//         {
//             count++;
//             j++;
//         }
        
//         substring = (char*)malloc(count+1);
//         strncpy(substring, str, count);
        
//         StrList_insertLast(List, substring);
        
//         j++;
//         count = 0;
//         str += j;
//         j = 0;
//         free(substring);
//     }
    
// }
#include <stdio.h>
#include <stdlib.h> // For malloc
#include <string.h>
#include "StrList.h""

typedef struct _Node {
    char* value;
    struct _Node* next;
} Node;

typedef struct _StrList {
    struct _Node* head;
    int size;
} StrList;

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


void StrList_insertLast(StrList* StrList,const char* data){
    Node *current = StrList->head;

    while (current->next != NULL){
        current = current->next;
    }
    Node* lemur = (Node*)malloc(sizeof(Node*)); // if doesn't work I am sad 

    lemur->value = data;
    current->next = lemur;
}
void StrList_insertAt(StrList* StrList,const char* data,int index){
    Node *current = StrList->head;
    for (int i = 0; i < index;i++){
        current = current->next;
    }
    Node* temp = current->next;
    Node* lemur = (Node*)malloc(sizeof(Node*)); // if doesn't work I am sad 
    lemur->value = data;
    lemur->next = temp;
}

char* StrList_firstData(const StrList* StrList){
    return StrList->head->value;
}

void StrList_print(const StrList* StrList){
    Node *current = StrList->head;
    while(current != NULL){
        printf("%d",current->value);
    }
}

void StrList_printAt(const StrList* Strlist,int index){
    Node *current = Strlist->head;
    for(int i = 0; i < index;i++){
        current = current->next;
    }
    printf("%d",current->value);
}

int StrList_printLen(const StrList* Strlist){
    int counter = 0;
    Node *current = Strlist->head;
    while (current != NULL){
        counter += strlen(current->next);
    }
    return counter;
}

int StrList_count(StrList* StrList, const char* data){
    Node *current = StrList->head;
    int counter = 0;
    while(current != NULL){
        if (strcmp(current->value,data)){
            counter += 1;
        }
    }
    return counter;
}


void StrList_remove(StrList* StrList, const char* data){
    Node *current = StrList->head;
    if (strcmp(current->value, data)){
        StrList = current->next;
    }
    while (current != NULL){
        if(strcmp(data,current->value)){

        }
    }
}

void StrList_removeAt(StrList* StrList, int index){

}

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){

}

StrList* StrList_clone(const StrList* Strlist){
    Node *current = Strlist->head;
    StrList* clone = StrList_alloc();
    clone->head = current;
    clone->size = Strlist->size;
    Node *cur_new = 
}

void StrList_reverse( StrList* StrList){

}

void StrList_sort( StrList* StrList){

}


int StrList_isSorted(StrList* StrList){
    Node *current = StrList->head;
    while (current->next != NULL){
        if(!strcmp(current->value,current->next->value)){
            return 0;
        }
    }
    return 1;
}


#include <stdio.h>
#include <stdlib.h> // For malloc
#include "StrList.h""

struct Node {
    char *value;
    struct Node *next;
};
struct StrList{
    struct Node *head;
    int size;
};
StrList* StrList_alloc(){
    StrList* newList = (StrList*)malloc(sizeof(StrList));
    if (newList == NULL) {
        return NULL;
    }
    
    newList->head = NULL; // Initialize the head to NULL
    newList->size =  0; // Initialize the size to  0
    
    return newList;
    
}
void StrList_free(StrList* StrList){

}

size_t StrList_size(const StrList* StrList){

}


void StrList_insertLast(StrList* StrList,const char* data){

}
void StrList_insertAt(StrList* StrList,const char* data,int index){

}

char* StrList_firstData(const StrList* StrList){

}

void StrList_print(const StrList* StrList){

}

void StrList_printAt(const StrList* Strlist,int index){

}

int StrList_printLen(const StrList* Strlist){

}

int StrList_count(StrList* StrList, const char* data){

}


void StrList_remove(StrList* StrList, const char* data){

}

void StrList_removeAt(StrList* StrList, int index){

}

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){

}

StrList* StrList_clone(const StrList* StrList){

}

void StrList_reverse( StrList* StrList){

}

void StrList_sort( StrList* StrList){

}


int StrList_isSorted(StrList* StrList){

}


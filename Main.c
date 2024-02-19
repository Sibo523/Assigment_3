#include <stdio.h>
#include "StrList.h"
int main()
{
    // char* data=(char *)malloc(sizeof(char *));
    char *data1="lol";
    char *data2="ll";
    StrList *list=StrList_alloc();
    StrList_insertLast(list,data1);
    StrList_insertLast(list,data2);
    StrList_insertAt(list,"ping",2);
    printf("%s\n",list->head->value);
    printf("%s\n",list->head->next->value);
    printf("%s\n",list->head->next->next->value);
    printf("%s data:\n",StrList_firstData(list));
    StrList_print(list);
    printf("seperate\n");
    StrList_printAt(list,2);
    printf("numbers of chars: %d\n",StrList_printLen(list));
    printf("number of times lol is in the list is: %d\n",StrList_count(list,"lol"));
    StrList* lemur =  StrList_clone(list);
    StrList_print(lemur);
    printf("Reversed:");
    StrList_reverse(lemur);
    StrList_print(lemur);
    StrList_remove(lemur,"lol");
    printf("removed:\n");
    StrList_print(lemur);
    printf("str print at:");
    StrList_printAt(lemur,0);
    printf("remove at 0:\n");
    StrList_removeAt(list,1);
    StrList_print(list);
    printf("check sort:\n");
    StrList_sort(list);

    /*char c;
    while ((c=getchar())!='0')
    {
        if(c=='1')
    }*/
    
    return 0;
}

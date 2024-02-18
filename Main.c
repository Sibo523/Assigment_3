#include "StrList.h"
#include <stdio.h>

int main()
{
    //char* data=(char *)malloc(sizeof(char *));
    char *data1="lol";
    char *data2="ll";
    StrList *list=StrList_alloc();
    StrList_insertLast(list,data1);
    StrList_insertLast(list,data2);
    StrList_insertAt(list,data1,3);
    printf("%s\n",list->_head->word);
    printf("%s\n",list->_head->_next->word);
    printf("%s\n",list->_head->_next->_next->word);
    printf("%s\n",StrList_firstData(list));
    StrList_print(list);
    StrList_printAt(list,2);
    printf("numbers of chars: %d\n",StrList_printLen(list));
    printf("number of times lol is in the list is: %d\n",StrList_count(list,"lol"));
    /*char c;
    while ((c=getchar())!='0')
    {
        if(c=='1')
    }*/
    
    return 0;
}
// #include <stdio.h>
// #include "StrList.h"
// int main()
// {
//     // char* data=(char *)malloc(sizeof(char *));
//     char *data1="z";
//     char *data2="a";
//     StrList *list=StrList_alloc();
//     // list->size = 3;
//     StrList_insertLast(list,data1);
//     StrList_insertLast(list,data2);
//     StrList_insertAt(list,"b",2);
//     list->size = 3;
//     printf("%s\n",list->head->value);
//     printf("%s\n",list->head->next->value);
//     printf("%s\n",list->head->next->next->value);
//     // printf("%s data:\n",StrList_firstData(list));
//     // StrList_print(list);
//     // printf("seperate\n");
//     // StrList_printAt(list,2);
//     // printf("numbers of chars: %d\n",StrList_printLen(list));
//     // printf("number of times lol is in the list is: %d\n",StrList_count(list,"lol"));
//     // StrList* lemur =  StrList_clone(list);
//     // StrList_print(lemur);
//     // printf("Reversed:");
//     // StrList_reverse(lemur);
//     // StrList_print(lemur);
//     // StrList_remove(lemur,"lol");
//     // printf("removed:\n");
//     // StrList_print(lemur);
//     // printf("str print at:");
//     // StrList_printAt(lemur,0);
//     // printf("remove at 0:\n");
//     // StrList_removeAt(list,1);
//     // StrList_print(list);
//     printf("check sort:\n");
//     StrList_sort(list);
//     StrList_print(list);

//     /*char c;
//     while ((c=getchar())!='0')
//     {
//         if(c=='1')
//     }*/
    
//     return 0;
// }
#include <stdio.h>
#include <string.h>
#include "StrList.h"

#define Max_Size_Str 100

int main(){
    int length;
    char *str = (char*)malloc(Max_Size_Str);
    int index;
    int num;
    struct _StrList *strlist = StrList_alloc();

    // printf("1 - Insert string to the list\n");
    // printf("2 - Insert string at a disired index\n");
    // printf("3 - Print the list\n");
    // printf("4 - Print the list length\n");
    // printf("5 - Print string at desired index\n");
    // printf("6 - Print the number of chars in the list\n");
    // printf("7 - Insert a string and print how many times it is found on the list\n");
    // printf("8 - Insert a string and remove all appearances from the list\n");
    // printf("9 - Remove string at a given index\n");
    // printf("10 - Reversing the list\n");
    // printf("11 - Deleting the list\n");
    // printf("12 - Sort the list in lexicographical order\n");
    // printf("13 - Check if the list sorted lexicographically\n");
    // printf("0 - Exit\n");

    scanf("%d", &num);
    StrList* list=  StrList_alloc();
    list->size = num;
    scanf("%s",str);
    Node* head = (Node*)malloc(sizeof(Node));
    head->value = str;
    while (num != 0)
    {
        if (num == 1)
        {
            scanf(" %d", &length);
            scanf(" %[^\n]s", str);
            str = realloc(str, strlen(str));

            // buildList(strlist, length, str);
        }
        
        if (num == 2)
        {
            scanf(" %d", &index);
            scanf(" %s", str);
            StrList_insertAt(strlist, str, index);
        }

        if (num == 3)
        {
            StrList_print(strlist);

        }

        if (num == 4)
        {
            printf("%zu\n", StrList_size(strlist));
        }

        if (num == 5)
        {
            scanf(" %d", &index);
            StrList_printAt(strlist, index);
        }

        if (num == 6)
        {
            printf("%d\n", StrList_printLen(strlist));
        }

        if (num == 7)
        {
            scanf(" %s", str);
            printf("%d\n", StrList_count(strlist, str)); 
        }

        if (num == 8)
        {
            scanf(" %s", str);
            StrList_remove(strlist, str);
        }

        if (num == 9)
        {
            scanf(" %d", &index);
            StrList_removeAt(strlist, index);
        }

        if (num == 10)
        {
            StrList_reverse(strlist);
        }

        if (num == 11)
        {
            StrList_free(strlist);
        }

        if (num == 12)
        {
            StrList_sort(strlist);
        }

        if (num == 13)
        {
            if (StrList_isSorted)
            {
                printf("true\n");
            }
            else
            {
                printf("false\n");
            }
        }
        
        scanf(" %d", &num);
    }
    free(str);
}
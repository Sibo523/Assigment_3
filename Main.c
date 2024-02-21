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
// #include <stdio.h>
// #include <string.h>
// #include "StrList.h"

// #define Max_Size_Str 100

// int main(){
//     int length;
//     char *str = (char*)malloc(Max_Size_Str);
//     int index;
//     int num;
//     struct _StrList *strlist = StrList_alloc();

//     printf("1 - Insert string to the list\n");
//     printf("2 - Insert string at a disired index\n");
//     printf("3 - Print the list\n");
//     printf("4 - Print the list length\n");
//     printf("5 - Print string at desired index\n");
//     printf("6 - Print the number of chars in the list\n");
//     printf("7 - Insert a string and print how many times it is found on the list\n");
//     printf("8 - Insert a string and remove all appearances from the list\n");
//     printf("9 - Remove string at a given index\n");
//     printf("10 - Reversing the list\n");
//     printf("11 - Deleting the list\n");
//     printf("12 - Sort the list in lexicographical order\n");
//     printf("13 - Check if the list sorted lexicographically\n");
//     printf("0 - Exit\n");
//     scanf("%d",&num);
//     while (num != 1){
//         printf("Still waiting for 1");
//         scanf("%d",&num);

//     }
//     printf("print the sze of the thing");
//     scanf("%d", &num);
//     StrList* list=  StrList_alloc();
//     list->size = num;

//     scanf("%s",str);
//     Node* head = (Node*)malloc(sizeof(Node));
//     head->value = str;
//     while (num != 0)
//     {
//         if (num == 1)
//         {
//             scanf(" %d", &length);
//             scanf(" %[^\n]s", str);
//             str =malloc(sizeof(str));
//            StrList StrList(str,length);
//         }
        
//         if (num == 2)
//         {
//             scanf(" %d", &index);
//             scanf(" %s", str);
//             StrList_insertAt(strlist, str, index);
//         }

//         if (num == 3)
//         {
//             StrList_print(strlist);

//         }

//         if (num == 4)
//         {
//             printf("%zu\n", StrList_size(strlist));
//         }

//         if (num == 5)
//         {
//             scanf(" %d", &index);
//             StrList_printAt(strlist, index);
//         }

//         if (num == 6)
//         {
//             printf("%d\n", StrList_printLen(strlist));
//         }

//         if (num == 7)
//         {
//             scanf(" %s", str);
//             printf("%d\n", StrList_count(strlist, str)); 
//         }

//         if (num == 8)
//         {
//             scanf(" %s", str);
//             StrList_remove(strlist, str);
//         }

//         if (num == 9)
//         {
//             scanf(" %d", &index);
//             StrList_removeAt(strlist, index);
//         }

//         if (num == 10)
//         {
//             StrList_reverse(strlist);
//         }

//         if (num == 11)
//         {
//             StrList_free(strlist);
//         }

//         if (num == 12)
//         {
//             StrList_sort(strlist);
//         }

//         if (num == 13)
//         {
//             if (StrList_isSorted)
//             {
//                 printf("true\n");
//             }
//             else
//             {
//                 printf("false\n");
//             }
//         }
        
//         scanf(" %d", &num);
//     }
//     free(str);
// }
#include <stdio.h>
#include <stdlib.h>
#include "StrList.h"
#define false 0
#define true 1
int main() {
    int number = 0;
    scanf("%d", &number);
    StrList *list = StrList_alloc();

    while (number != 0) {
        if (number == 1) {
            int temp = 0;
            scanf("%d", &temp);
            list->size = temp;
            for (int i = 0; i < temp; i++) {
                char *data = (char *)malloc(sizeof(char) * 21);
                scanf("%s", data);
                StrList_insertLast(list, data);
            }
        } else if (number == 2) {
            int temp = 0;
            scanf("%d", &temp);
            char *data = (char *)malloc(sizeof(char) * 100);
            scanf("%s", data);
            StrList_insertAt(list, data, temp);
        } else if (number == 3) {
            StrList_print(list);
        
        } else if (number == 4) {
           printf( "%d\n",(int)StrList_size(list));
        } else if (number == 5) {
            int index = 0;
            scanf("%d", &index);
            StrList_printAt(list, index);
        } else if (number == 6) {
            int i =StrList_printLen(list);
            printf("%d\n", i);
        } else if (number == 7) {
            char *data = (char *)malloc(sizeof(char) * 100);
            scanf("%s", data);
           int y=  StrList_count(list, data);
           printf("%d\n",y);
            free(data);
        } else if (number == 8) {
            char *data = (char *)malloc(sizeof(char) * 100);
            scanf("%s", data);
            StrList_remove(list, data);
            free(data);
        } else if (number == 9) {
            int index = 0;
            scanf("%d", &index);
            StrList_removeAt(list, index);
        } else if (number == 10) {
            StrList_reverse(list);
        } else if (number == 11) {
            StrList_free(list);
           // return 0;
        } else if (number == 12) {
            StrList_sort(list);
        } else if (number == 13) {
            if (StrList_isSorted(list)) {
                printf("true \n");
            } else {
                printf("false \n");
            }
            // int i =StrList_isSorted(list);
            // printf("%d",i);
        }
        scanf("%d", &number); // Read next number for the next iteration
    }
    free(list);
    return 0;
}
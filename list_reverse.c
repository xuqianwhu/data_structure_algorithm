#include "stdio.h"

typedef struct node
{
    int             value;
    struct node*    next;
} node;

node list[10], *head = NULL;

void initializeList(node* list, int size)
{
    int i=0;

    while(i < size)
    {
        //list[i].value = i;
        (list+i)->value = i;
        list[i].next  = &list[i+1];
        i++;
    }
    list[size-1].next = NULL;
    head = list;
}

void reverseListRecursive(node* cur, node* pre)
{
    if(NULL != cur->next)
    {
        reverseListRecursive(cur->next, cur);
    }
    else
    {
        head = cur;
    }
    cur->next = pre;
}

void reverseListCommon(node* cur)
{
    node *pre=NULL, *tmp;

    if(NULL == cur->next)
    {
        return;
    }

    while(cur)
    {
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    head = pre;
}

void printList(node* head)
{
    printf("List: ");
    while(head != NULL)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

void main()
{
    initializeList(list, 10);
    printList(head);
    reverseListRecursive(head, NULL);
    printList(head);
    reverseListCommon(head);
    printList(head);
}

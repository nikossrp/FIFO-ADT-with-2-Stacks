#include <stdio.h>
#include <stdlib.h>
#include "Interface.h"

void Initialize(Queue* Q)
{
    Q->Input.ItemList1 = NULL;
    Q->Output.ItemList2 = NULL;
}

int Empty1(Stack1* S)
{
    return S->ItemList1 == NULL;
}

int Empty2(Stack2* S)
{
    return S->ItemList2 == NULL;
}

int Empty(Queue* Q)
{
    return (Empty1(&(Q->Input)) && Empty2(&(Q->Output)));   
}

int Full(Queue* Q)  //full otan gemisei to heap
{
    return 0;
} 

void Pop(Stack2* S, ItemType* X)
{
    StackNode* Temp;

    if(S->ItemList2 == NULL) printf("Stack is empty\n");
    else{
        Temp =S->ItemList2;
        *X = Temp->Item;
        S->ItemList2 = Temp->Link;
        free(Temp);
    }
}

void Push(Stack1* S, ItemType X)
{
    StackNode* Temp;
    Temp = (StackNode* )malloc(sizeof(StackNode));

    if(Temp == NULL) printf("No space available");
    else{
        Temp->Link = S->ItemList1;
        Temp->Item = X;
        S->ItemList1 = Temp;
    }
}

void Insert(ItemType R, Queue* Q)
{
    Push(&(Q->Input), R);    //push in the first stack
}

void reverse(Stack1* S, Stack2* X)    //from first stack to second
{
    StackNode* Temp;   
    Temp = S->ItemList1->Link;  
    S->ItemList1->Link = X->ItemList2;   
    X->ItemList2 = S->ItemList1;
     S->ItemList1 = Temp;
}

// take the items out of one stack and put them in the other one
// structure will be FIFO like queue
void enqueue(Stack1* In, Stack2* Out )  
{   
    if(Empty2(Out)) 
    while(!Empty1(In)){    
        reverse(In, Out);
    }
}

void Remove(Queue* Q, ItemType* F)
{
    enqueue(&(Q->Input), &(Q->Output));
    Pop(&(Q->Output), F);
}

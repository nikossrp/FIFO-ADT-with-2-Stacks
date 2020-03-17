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
    return (Empty1(&(Q->Input)) && Empty2(&(Q->Output)));    //einai adia mono otan einai kai oi dyo stoives adies
}

int Full(Queue* Q)  //full otan gemisei to heap
{
    return 0;
} 

void Pop(Stack2* S, ItemType* X)
{
    StackNode* Temp;

    if(S->ItemList2 == NULL) printf("H stoiva einai kenh den uparxei stoixeio na bgaleis");
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

    if(Temp == NULL) printf("Den exoume xwro");
    else{
        Temp->Link = S->ItemList1;
        Temp->Item = X;
        S->ItemList1 = Temp;
    }
}

void Insert(ItemType R, Queue* Q)
{
//  printf("Insert the item %d\n", R);
    Push(&(Q->Input), R);    //ta bazw sthn prwth stoiva
}

void reverse(Stack1* S, Stack2* X)    //apo thn prwth stoiva sthn defterh
{
//  printf("Put item %d in stoiva2\n", S->ItemList1->Item);
    StackNode* Temp;   
    Temp = S->ItemList1->Link;  //bazw ton prosorino deikth na deixnh sto 2o stoixeio ths stoivas
    S->ItemList1->Link = X->ItemList2;   
    X->ItemList2 = S->ItemList1;
     S->ItemList1 = Temp;
}

//gia na bgalw ta stoixeia apo thn mia stoiva kai na ta balw stin allh stoiva me thn antistrofh seira
//wste na ta bgalw anapoda diladh na exw domh FIFO opws sthn oura:
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

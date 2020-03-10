#include "Types.h"
void Initialize(Queue* );
int Empty(Queue* );
int Full(Queue* );
void Insert(ItemType , Queue* );
void Remove(Queue* , ItemType* );   
int Empty1(Stack1* );           
int Empty2(Stack2* );
void Push(Stack1* , ItemType );    //push gia thn prwti stoiva
void enqueue(Stack1* , Stack2*  );    //gia thn anastrofh apo thn 1 -> 2 wste na einai mia domh FIFO
void Pop(Stack2* , ItemType* );    //pop gia thn 2h stoiva

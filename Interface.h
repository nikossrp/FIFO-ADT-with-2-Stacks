#include "Types.h"
void Initialize(Queue* );
int Empty(Queue* );
int Full(Queue* );
void Insert(ItemType , Queue* );
void Remove(Queue* , ItemType* );   
int Empty1(Stack1* );           
int Empty2(Stack2* );
void Push(Stack1* , ItemType );    //push for the first stack
void enqueue(Stack1* , Stack2*  );    //for the reverse from stack1 to stack2
void Pop(Stack2* , ItemType* );    //pop for the second stack

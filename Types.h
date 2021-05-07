typedef int ItemType;
typedef struct StackNodeTag{   
   ItemType Item;
   struct StackNodeTag * Link;

}StackNode;

typedef struct{     
   StackNode* ItemList1; 
}Stack1;

typedef struct{     
   StackNode* ItemList2; 
}Stack2;

typedef struct{
   Stack1 Input;
   Stack2 Output;
}Queue;

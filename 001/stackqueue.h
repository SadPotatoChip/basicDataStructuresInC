typedef struct stack_t{
	node *top;
}stack;

typedef struct queue_t{
	node *start;	
}queue;
void push(stack *s, int val);
node* pop(stack *s);
void enqueue(queue *q, int val);
void enqueueFromNode(queue *q, node* x);
node* dequeue(queue *q);

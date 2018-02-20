typedef struct node_t{
	int val;
	struct node_t *next;
	struct node_t *prev;
}node;
int getNodeVal(node target);
node newNodeV(int val);
node newNode(int val,node *next);
node newNodeP(int val,node *next,node *prev);
node* addNode(node *head, int val);
node* addNodeFromNode(node *head, node *new);
node* addNodeToStart(node *head, int val);
node listFromNumbers(node *head, int n, ...);
node flipList(node **head);
int printList(node *head);
int freeList(node *head);

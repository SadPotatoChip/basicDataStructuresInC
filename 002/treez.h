typedef struct nodeT_t{
	int val;
	struct nodeT_t *left;
	struct nodeT_t *right;
}node;
void getNodeVal(node* x);
void dfs(node* head);
void bfs(node* head);
void _bfs(node* head, node* q);
void enqueue(node* q, node* new);
node* dequeue(node** q);

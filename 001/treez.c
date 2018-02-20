#include <stdio.h>
#include <stdlib.h>
#include "listz.h"
#include "treez.h"
#include "stackqueue.h"

void getNodeValT(nodeT* x){
	printf("%d\n",x->val);
	
}

/*node*/ addNodeTBallanced(nodeT *head,int val){
	if(head==NULL){
		head=malloc(sizeof(nodeT));
		head->val=val;
	}
	
	queue *q=malloc(sizeof(queue));
	enqueueFromNode(q,head->left);
	enqueueFromNode(q,head->right);
	addNodeTBallanced(dequeue(q),val);			
}*/


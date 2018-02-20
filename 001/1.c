#include <stdio.h>
#include <stdlib.h>
#include "listz.h"
#include "treez.h"
#include "stackqueue.h"


int main(int argc, char **argv){
	queue *q=malloc(sizeof(queue));
	enqueue(q,0);
	enqueue(q,1);
	enqueue(q,2);
	enqueue(q,3);
	node *tmp;
	
	tmp=dequeue(q);
	printf("%d\n",tmp->val);
	
		
	while(tmp=dequeue(q)){
		printf("%d ",tmp->val);
	}
	
	return 0;
}